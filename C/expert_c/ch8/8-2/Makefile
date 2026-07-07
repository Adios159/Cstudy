CC      = gcc
CFLAGS  = -Wall -Wextra -g -std=c11   # -g: gdb 디버깅용 심볼 포함, -Wall/-Wextra: 경고 최대화
 
TARGET  = main
OBJS    = main.o person.o student.o
 
# 최종 실행파일 생성 (기본 타겟)
all: $(TARGET)
 
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
 
# 각 .c 파일 -> .o (오브젝트 파일: 컴파일은 됐지만 아직 링크 전 상태) 컴파일 규칙
# 헤더 파일이 바뀌면 다시 컴파일되도록 의존성에 명시
main.o: main.c person.h person_s.h student.h
	$(CC) $(CFLAGS) -c main.c
 
person.o: person.c person.h person_s.h
	$(CC) $(CFLAGS) -c person.c
 
student.o: student.c student.h person.h person_s.h
	$(CC) $(CFLAGS) -c student.c
 
# 빌드 결과물 정리
clean:
	rm -f $(TARGET) $(OBJS)
 
# 파일 이름과 겹쳐도 항상 실행되도록 (all, clean은 실제 파일이 아님)
.PHONY: all clean