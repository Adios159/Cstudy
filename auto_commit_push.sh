#!/usr/bin/env bash
# auto_commit_push.sh
# 변경 파일을 폴더별로 묶고, 기존 커밋 기록의 형식에 맞는 메시지를 제안한 뒤 커밋하고 푸시한다.
#
# 사용법:
#   ./auto_commit_push.sh                  # 묶음마다 메시지를 확인/수정 (Enter: 커밋, 비우면 건너뜀)
#   ./auto_commit_push.sh --dry-run        # 미리보기만
#   ./auto_commit_push.sh -y               # 제안 메시지 그대로 전부 커밋
#   ./auto_commit_push.sh -m "폴더구조 변경"  # 전체를 커밋 하나로 (파일 이동/정리용)
#   ./auto_commit_push.sh --no-push        # 커밋만
#   ./auto_commit_push.sh --with-deletions # 삭제된 파일도 묻지 않고 커밋
#
# junk/ 는 항상 제외한다. 내용이 같은 채 위치만 바뀐 파일은 "폴더구조 변경"으로 묶고,
# 그 밖의 삭제된 파일은 따로 확인받는다.

set -euo pipefail

EXCLUDES=("junk/")

DRY=0 YES=0 PUSH=1 WITH_DEL=0 ONE_MSG=""
while (($#)); do
    case "$1" in
        --dry-run)        DRY=1 ;;
        -y|--yes)         YES=1 ;;
        --no-push)        PUSH=0 ;;
        --with-deletions) WITH_DEL=1 ;;
        -m)               ONE_MSG="${2:?-m 뒤에 커밋 메시지가 필요합니다}"; shift ;;
        -h|--help)        sed -n '2,15p' "$0"; exit 0 ;;
        *)                echo "알 수 없는 옵션: $1" >&2; exit 1 ;;
    esac
    shift
done

die() { echo "오류: $*" >&2; exit 1; }

cd "$(git -C "$(dirname "$(realpath "$0")")" rev-parse --show-toplevel)"
export GIT_LITERAL_PATHSPECS=1   # 파일명의 *, [ ] 등을 그대로 취급

# ---------- 저장소 상태 확인 ----------
branch=$(git symbolic-ref --quiet --short HEAD) || die "detached HEAD 상태입니다."
gitdir=$(git rev-parse --git-dir)
for f in MERGE_HEAD CHERRY_PICK_HEAD REVERT_HEAD rebase-merge rebase-apply; do
    [[ -e "$gitdir/$f" ]] && die "merge/rebase 등이 진행 중입니다. 먼저 마무리하세요."
done
[[ -z "$(git diff --name-only --diff-filter=U)" ]] || die "충돌이 해결되지 않은 파일이 있습니다."
(( DRY || YES )) || [[ -t 0 ]] || die "터미널이 아닙니다. -y 또는 --dry-run 을 사용하세요."

# GitHub SSH: 22번 포트가 막힌 네트워크에서는 443번으로 접속 (호스트 키 검증은 github.com 것을 그대로 사용)
setup_ssh() {
    [[ -z "${GIT_SSH_COMMAND:-}" && -z "$(git config core.sshCommand)" ]] || return 0
    local url
    url=$(git remote get-url "$(git config "branch.$branch.remote" || echo origin)" 2>/dev/null) || return 0
    [[ "$url" == git@github.com:* || "$url" == ssh://git@github.com/* ]] || return 0
    export GIT_SSH_COMMAND="ssh -o ConnectTimeout=10"
    if ! timeout 5 bash -c 'exec 3<>/dev/tcp/github.com/22' 2>/dev/null; then
        echo "SSH 22번 포트에 연결할 수 없어 ssh.github.com:443 을 사용합니다."
        GIT_SSH_COMMAND+=" -o HostName=ssh.github.com -p 443 -o HostKeyAlias=github.com"
    fi
}

if (( PUSH && !DRY )); then
    echo "원격 저장소 확인 중..."
    setup_ssh
    if git fetch --quiet; then
        behind=$(git rev-list --count 'HEAD..@{u}' 2>/dev/null || echo 0)
        (( behind == 0 )) || die "원격이 ${behind}개 커밋 앞서 있습니다. 'git pull --rebase --autostash' 후 다시 실행하세요."
    else
        echo "경고: fetch 실패. 커밋은 진행하지만 푸시가 실패할 수 있습니다."
    fi
fi

# ---------- 메시지 생성 ----------

# "머리말(N)" 형식: 같은 머리말의 커밋 수 + 1
numbered() {
    local n
    n=$(git log --format=%s | awk -v p="$1(" 'index($0, p) == 1 { c++ } END { print c + 1 }')
    echo "$1($n)"
}

# 해당 폴더의 직전 주제를 이어받아 번호를 올림. 기록이 없으면 기본값
# $1=폴더(비우면 전체 기록)  $2=머리말  $3=기본 메시지
series() {
    local last
    last=$(git log --format=%s ${1:+-- "$1"} | awk -v p="$2:" 'index($0, p) == 1 && !f { print; f = 1 }')
    if [[ -z "$last" ]]; then echo "$3"; return; fi
    [[ "$last" =~ ^(.*)\([^()]*끝\)$ ]] && last="${BASH_REMATCH[1]}"
    if [[ "$last" =~ ^(.*)\(([0-9]+)\)$ ]]; then
        echo "${BASH_REMATCH[1]}($(( BASH_REMATCH[2] + 1 )))"
    else
        echo "$last(2)"
    fi
}

declare -A TOPIC=([Graph]=그래프 [sort]=정렬 [search]=검색 [hash]=해시)
declare -A KIND=([textbook]="교재 코드 따라치기" [problems]="문제 풀이")

# 파일 경로 -> KEY(묶음 이름), MSG(제안 메시지)
classify() {
    local p="$1" d
    d=$(dirname "$p")
    if [[ "$p" =~ ^C/DSA/exam/final/([^/]+)/(textbook|problems)/ ]]; then
        local t="${BASH_REMATCH[1]}" k="${BASH_REMATCH[2]}"
        KEY="final/$t/$k"
        MSG=$(numbered "알고리즘 기말고사 대비-${TOPIC[$t]:-$t} ${KIND[$k]}")
    elif [[ "$p" =~ ^C/DSA/(exam/)?mid_term/ ]]; then
        KEY="mid_term"; MSG=$(numbered "알고리즘 중간고사 공부")
    elif [[ "$p" =~ ^C/DSA/Class/(week[0-9]+)/ ]]; then
        KEY="class/${BASH_REMATCH[1]}"; MSG="알고리즘 수업 실습: ${BASH_REMATCH[1]}"
    elif [[ "$p" =~ ^(C/TCP-IP/(ch[0-9]+))/ ]]; then
        KEY="${BASH_REMATCH[1]}"
        MSG=$(series "$KEY" "소켓 프로그래밍" "소켓 프로그래밍: ${BASH_REMATCH[2]}")
    elif [[ "$p" =~ ^(C/expert_c/(ch[0-9]+))/ ]]; then
        KEY="${BASH_REMATCH[1]}"
        MSG=$(series "$KEY" "전문가를 위한 C" "전문가를 위한 C: ${BASH_REMATCH[2]}")
    elif [[ "$p" =~ ^(C\+\+/expert_C\+\+/(ch[0-9]+))/ ]]; then
        KEY="${BASH_REMATCH[1]}"
        MSG=$(series "$KEY" "전문가를 위한 C++" "전문가를 위한 C++: ${BASH_REMATCH[2]}")
    elif [[ "$p" =~ ^(C\+\+/(C\+\+basic/)?STL/pt[0-9]+/ch([0-9]+))/ ]]; then
        KEY="${BASH_REMATCH[1]}"
        local n="${BASH_REMATCH[3]}"
        MSG=$(series "" "STL pt$n" "STL pt$n: ch$n")   # 폴더를 옮겨도 번호 유지
    elif [[ "$p" =~ ^(C\+\+/PS/algorithm_for_PS/ch([0-9]+))/ ]]; then
        KEY="${BASH_REMATCH[1]}"
        local h="실전 알고리즘 ${BASH_REMATCH[2]}장"
        MSG=$(series "" "$h" "$h")
    elif [[ "$p" =~ ^C\+\+/PS/contest/atcoder/.*(a[bwrg]c[0-9]+)/[^/]+\.cpp$ ]]; then
        KEY="$d"; MSG="${BASH_REMATCH[1]}"          # 문제 번호는 아래에서 붙임
    elif [[ "$p" =~ ^C\+\+/PS/contest/codeforces/(Div[0-9]+)/([0-9]+)/[^/]+\.cpp$ ]]; then
        KEY="$d"; MSG="${BASH_REMATCH[1]} ${BASH_REMATCH[2]}"
    elif [[ "$p" =~ /ThisIsDnA/([^/]+)/ ]]; then
        KEY="ThisIsDnA/${BASH_REMATCH[1]}"; MSG="이것이 자료구조&알고리즘이다 ${BASH_REMATCH[1]}"
    elif [[ "$p" =~ ^C/DSA/Practice/(ch[0-9]+)/ ]]; then
        KEY="practice/${BASH_REMATCH[1]}"; MSG="자료구조&알고리즘 연습문제: ${BASH_REMATCH[1]}"
    elif [[ "$p" == "README.md" ]]; then
        KEY="readme"; MSG="리드미 업데이트"
    elif [[ "$p" == ".gitignore" ]]; then
        KEY="gitignore"; MSG="깃 이그노어 업데이트"
    elif [[ "$p" == *.sh ]]; then
        KEY="scripts"; MSG="스크립트 업데이트"
    else
        KEY="etc/$d"
        [[ "$d" == "." ]] && MSG="파일 업데이트" || MSG="파일 업데이트: $d"
    fi
}

# ---------- 변경 파일 수집 및 묶기 ----------
declare -A FILES=() MSGS=() LETTERS=() MOVED=()
KEYS=() DELETED=() SKIPPED=()

excluded() {
    local ex
    for ex in "${EXCLUDES[@]}"; do [[ "$1" == "$ex"* ]] && return 0; done
    return 1
}

# 이동 감지: 임시 index에 전부 담아 HEAD와 비교 (실제 index는 건드리지 않음)
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT
[[ -f "$gitdir/index" ]] && cp "$gitdir/index" "$tmp/index"
specs=(.)
for ex in "${EXCLUDES[@]}"; do specs+=(":(exclude)${ex%/}"); done
GIT_INDEX_FILE="$tmp/index" GIT_LITERAL_PATHSPECS=0 git add -A -- "${specs[@]}"
while IFS= read -r -d '' st; do
    IFS= read -r -d '' a
    [[ "$st" == R* ]] || continue
    IFS= read -r -d '' b
    excluded "$a" || excluded "$b" && continue
    MOVED[$a]=1 MOVED[$b]=1
    FILES[moved]+="$a"$'\n'"$b"$'\n'
done < <(GIT_INDEX_FILE="$tmp/index" git diff --cached --name-status -z -M100%)
if (( ${#MOVED[@]} )); then KEYS+=("moved"); MSGS[moved]="폴더구조 변경"; fi

while IFS= read -r -d '' entry; do
    status="${entry:0:2}" path="${entry:3}"
    excluded "$path" && { SKIPPED+=("$path"); continue; }
    [[ -n "${MOVED[$path]:-}" ]] && continue
    if [[ "$status" == *D* && ! -e "$path" ]]; then DELETED+=("$path"); continue; fi
    classify "$path"
    if [[ -z "${FILES[$KEY]:-}" ]]; then KEYS+=("$KEY"); MSGS[$KEY]="$MSG"; fi
    FILES[$KEY]+="$path"$'\n'
    if [[ "$path" =~ ^C\+\+/PS/contest/.*/([a-z])\.cpp$ ]]; then
        LETTERS[$KEY]+="${LETTERS[$KEY]:+, }${BASH_REMATCH[1]}"
    fi
done < <(git status --porcelain=v1 -z --untracked-files=all --no-renames)

for k in "${!LETTERS[@]}"; do MSGS[$k]+="(${LETTERS[$k]})"; done

if (( ${#SKIPPED[@]} )); then
    echo "제외한 파일 ${#SKIPPED[@]}개 (${EXCLUDES[*]})"
fi

# -m: 모든 묶음을 하나로
if [[ -n "$ONE_MSG" && ${#KEYS[@]} -gt 0 ]]; then
    all=""
    for k in "${KEYS[@]}"; do all+="${FILES[$k]}"; done
    KEYS=("all"); FILES[all]="$all"; MSGS[all]="$ONE_MSG"
fi

# ---------- 커밋 ----------
show() { printf '    %s\n' "$@"; }

# 지정한 파일만 커밋 (미리 stage 해둔 다른 파일은 건드리지 않음)
commit_paths() {
    local msg="$1" f; shift
    for f in "$@"; do
        if [[ -e "$f" || -L "$f" ]]; then git add -- "$f"
        else git rm --cached --quiet --ignore-unmatch -- "$f"
        fi
    done
    git commit --quiet -m "$msg" -- "$@"
    git log -1 --format='  => %h %s'
}

# 삭제 파일 처리: -m 이면 같은 커밋에 합치고, 아니면 "파일 삭제"로 따로 커밋
if (( ${#DELETED[@]} )); then
    echo
    echo "[삭제된 파일 ${#DELETED[@]}개]"
    show "${DELETED[@]}"
    ok=$WITH_DEL
    if (( !ok && !DRY && !YES )); then
        read -r -p "  이 삭제를 커밋할까요? [y/N] " ans
        [[ "$ans" =~ ^[yY]$ ]] && ok=1
    fi
    if (( ok )); then
        if [[ -z "$ONE_MSG" ]]; then
            KEYS+=("deleted"); MSGS[deleted]="파일 삭제"
        elif (( ${#KEYS[@]} == 0 )); then
            KEYS=("all"); MSGS[all]="$ONE_MSG"
        fi
        target="deleted"; [[ -n "$ONE_MSG" ]] && target="all"
        FILES[$target]+="$(printf '%s\n' "${DELETED[@]}")"$'\n'
    elif (( !DRY )); then
        echo "  삭제는 커밋하지 않습니다."
    fi
fi

total=${#KEYS[@]} i=0
(( total )) || echo "커밋할 변경 사항이 없습니다."

for k in ${KEYS[@]+"${KEYS[@]}"}; do
    i=$((i + 1))
    mapfile -t files < <(printf '%s' "${FILES[$k]}" | sed '/^$/d')
    msg="${MSGS[$k]}"
    echo
    echo "[$i/$total] $msg"
    show "${files[@]}"
    (( DRY )) && continue
    if (( !YES )) && [[ -z "$ONE_MSG" && "$k" != "deleted" ]]; then
        read -r -e -i "$msg" -p "  메시지> " msg
        [[ -n "${msg// /}" ]] || { echo "  건너뜀"; continue; }
    fi
    commit_paths "$msg" "${files[@]}"
done

(( DRY )) && exit 0

# ---------- 푸시 ----------
(( PUSH )) || exit 0
echo
if git rev-parse --quiet --verify '@{u}' >/dev/null; then
    ahead=$(git rev-list --count '@{u}..HEAD')
    (( ahead )) || { echo "푸시할 커밋이 없습니다."; exit 0; }
    echo "${ahead}개 커밋을 푸시합니다."
    git push || die "푸시 실패. 커밋은 로컬에 남아 있으니 'git push'로 다시 시도하세요."
else
    git push -u origin "$branch" || die "푸시 실패."
fi
echo "완료."
