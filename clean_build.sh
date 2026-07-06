#!/usr/bin/env bash
# clean_build.sh
# 지정한 폴더(기본값: 현재 폴더) 하위의 모든 오브젝트 파일과 실행 파일을 재귀적으로 삭제하는 스크립트
#
# 사용법:
#   ./clean_build.sh [대상_폴더] [--dry-run]
#
# 예시:
#   ./clean_build.sh                # 현재 폴더 정리
#   ./clean_build.sh ~/Cstudy        # 지정 폴더 정리
#   ./clean_build.sh ~/Cstudy --dry-run   # 실제로 지우지 않고 삭제될 파일만 미리 확인

set -euo pipefail

TARGET_DIR="."
DRY_RUN=0

# 인자 파싱 (순서 상관없이 --dry-run 인식)
for arg in "$@"; do
    if [ "$arg" = "--dry-run" ]; then
        DRY_RUN=1
    else
        TARGET_DIR="$arg"
    fi
done

if [ ! -d "$TARGET_DIR" ]; then
    echo "오류: '$TARGET_DIR' 디렉토리를 찾을 수 없음" >&2
    exit 1
fi

echo "대상 디렉토리 : $(realpath "$TARGET_DIR")"
[ "$DRY_RUN" -eq 1 ] && echo "모드          : DRY-RUN (실제 삭제 안 함)"
echo "----------------------------------------"

DELETED_COUNT=0

remove_file() {
    local f="$1"
    if [ "$DRY_RUN" -eq 1 ]; then
        echo "[DRY-RUN] 삭제 예정: $f"
    else
        echo "삭제: $f"
        rm -f "$f"
    fi
    DELETED_COUNT=$((DELETED_COUNT + 1))
}

# 1) 오브젝트 파일 (.o, .obj)
while IFS= read -r -d '' file; do
    remove_file "$file"
done < <(find "$TARGET_DIR" -type f \( -name "*.o" -o -name "*.obj" \) -print0)

# 2) 확장자로 구분되는 실행 파일 (.exe, .out)
while IFS= read -r -d '' file; do
    remove_file "$file"
done < <(find "$TARGET_DIR" -type f \( -name "*.exe" -o -name "*.out" \) -print0)

# 3) 확장자 없는 리눅스 ELF 실행 파일 (gcc/g++ 컴파일 결과, 예: gcc main.c -o main)
#    조건: 확장자 없음 + 실행 권한 있음 + file 명령어로 ELF 확인 + 같은 이름의 .c/.cpp 소스 존재
while IFS= read -r -d '' file; do
    name=$(basename "$file")
    dir=$(dirname "$file")

    [[ "$name" == *.* ]] && continue      # 확장자 있는 파일은 제외
    [ -x "$file" ] || continue            # 실행 권한 없으면 제외
    file "$file" | grep -q "ELF" || continue   # ELF 바이너리 아니면 제외

    if [ -f "$dir/$name.c" ] || [ -f "$dir/$name.cpp" ]; then
        remove_file "$file"
    fi
done < <(find "$TARGET_DIR" -type f -print0)

echo "----------------------------------------"
if [ "$DRY_RUN" -eq 1 ]; then
    echo "총 ${DELETED_COUNT}개 파일이 삭제 대상으로 확인됨 (실제 삭제 없음)"
else
    echo "총 ${DELETED_COUNT}개 파일 삭제 완료"
fi