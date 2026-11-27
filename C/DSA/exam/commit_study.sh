#!/usr/bin/env bash
# 기말고사 대비 변경분을 (주제 × 교재/문제) 단위로 분리해 커밋 메시지를 보여주고,
# y/n 확인 후 커밋한다.
# 메시지 형식: 알고리즘 기말고사 대비-<주제> <교재 코드 따라치기|문제 풀이>(N)
# N은 git log에서 같은 접두사의 커밋 수 + 1.
#
# 사용법:  ./commit_study.sh            # 미리보기 후 y/n
#          ./commit_study.sh --dry-run  # 미리보기만
set -euo pipefail

cd "$(git -C "$(dirname "$0")" rev-parse --show-toplevel)"
BASE="C/DSA/exam/final"
DRY=0; [[ "${1:-}" == "--dry-run" ]] && DRY=1
TRAILER="Co-Authored-By: Claude Sonnet 5.5 <noreply@anthropic.com>"

# 디렉터리명 -> 한글 주제 (새 주제는 여기에 추가)
declare -A TOPIC=([Graph]=그래프 [sort]=정렬 [search]=검색)
ORDER=(Graph sort search)          # 주제 처리 순서
KINDS=(textbook problems)          # 교재 -> 문제
declare -A KIND_LABEL=([textbook]="교재 코드 따라치기" [problems]="문제 풀이")

# 변경/신규 파일 목록 (.gitignore 대상 제외)
changed=$( { git diff --name-only; git ls-files --others --exclude-standard; } | sort -u )

msgs=(); filelists=()
for dir in "${ORDER[@]}"; do
  for kind in "${KINDS[@]}"; do
    prefix="$BASE/$dir/$kind/"
    files=$(grep -F "$prefix" <<<"$changed" || true)
    [[ -z "$files" ]] && continue

    head="알고리즘 기말고사 대비-${TOPIC[$dir]} ${KIND_LABEL[$kind]}"
    n=$(( $(git log --oneline --fixed-strings --grep="$head(" 2>/dev/null | wc -l || true) + 1 ))
    msgs+=("$head($n)"); filelists+=("$files")
    echo "[${#msgs[@]}] $head($n)"
    sed "s|^$prefix|      |" <<<"$files"
  done
done

if (( ${#msgs[@]} == 0 )); then echo "커밋할 변경 사항이 없습니다."; exit 0; fi
(( DRY )) && exit 0

read -r -p "위 ${#msgs[@]}개 커밋을 진행할까요? [y/N] " ans
[[ "$ans" =~ ^[yY]$ ]] || { echo "취소했습니다."; exit 0; }

for i in "${!msgs[@]}"; do
  mapfile -t f <<<"${filelists[$i]}"
  git add -- "${f[@]}"
  git commit -q -m "${msgs[$i]}" -m "$TRAILER"
  git log --oneline -1
done
