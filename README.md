# C_STUDY

> C/C++ 알고리즘 문제풀이 및 자료구조 학습을 기록하는 저장소입니다.
> AtCoder 및 Codeforces 문제풀이, 교재 실습, 자료구조 직접 구현을 포함합니다.

![Language](https://img.shields.io/badge/language-C%2FC%2B%2B-blue)
![Platform](https://img.shields.io/badge/platform-Windows%2011-lightgrey)
![Compiler](https://img.shields.io/badge/compiler-GCC%20(MinGW64)-green)
![AtCoder](https://img.shields.io/badge/AtCoder-ABC%20%7C%20AWC-orange)
![Codeforces](https://img.shields.io/badge/Codeforces-Div.2-red)

---

## 주요 특징

- **자료구조 직접 구현** — 연결 리스트·스택·큐를 C로 밑바닥부터 구현, 다항식·MP3 플레이어 등 응용 프로젝트 포함
- **알고리즘 문제풀이** — AtCoder ABC/AWC, Codeforces Div.2 문제를 꾸준히 풀며 실력 향상 중
- **교재 병행 학습** — 명품 C++·포르잔 C++·Expert C/C++ 교재를 통해 언어 기반 다지기

---

## 폴더 구조

```
C_STUDY/
├── C/                              # C 언어 학습
│   ├── DataStructure/              # 자료구조 직접 구현
│   │   ├── LinkedList/             # 연결 리스트 (단순/이중/원형) 및 응용
│   │   ├── Stack/                  # 스택 구현 및 응용
│   │   └── queue/                  # 큐 구현 및 응용
│   └── expert_c/                   # Expert C 학습 자료
│       └── ch1/                    # 1장 예제 코드
├── C++/                            # C++ 학습 및 문제풀이
│   ├── HighendC++/                 # 명품 C++ 교재 학습
│   │   ├── ch5/                    # 함수
│   │   │   ├── example/            # 예제 코드 (11개)
│   │   │   └── exercise/           # 연습문제 (7개)
│   │   ├── ch6/                    # 클래스와 객체
│   │   │   ├── example/            # 예제 코드 (11개)
│   │   │   └── exercise/           # 연습문제 (6개)
│   │   └── ch7/                    # 생성자와 소멸자
│   │       ├── example/            # 예제 코드 (11개)
│   │       └── exercise/           # 연습문제 (6개)
│   ├── expertC++/                  # Expert C++ 학습 자료
│   ├── atcoder/                    # AtCoder 문제풀이
│   ├── codeforces/                 # Codeforces 문제풀이
│   └── forzan_cpp/                 # 포르잔 C++ 학습 코드
│       ├── ch8/                    # 파일 I/O, 다중 파일 클래스 설계
│       └── (ch4, ch5 예제)
├── .vscode/                        # VSCode 빌드 설정
├── CLAUDE.md
├── .gitignore
└── README.md
```

---

## 디렉토리 설명

| 폴더 | 설명 |
|------|------|
| `C/DataStructure/LinkedList/` | 단순/이중/원형 연결 리스트, 문자열·큐·스택 응용, 다항식·희소행렬·MP3 시뮬레이션 등 구현 |
| `C/DataStructure/Stack/` | 배열·동적 스택 구현, 괄호 검사, 중위→후위 변환, 후위 계산 |
| `C/DataStructure/queue/` | 선형·원형 큐, 덱, 은행 시뮬레이션, 버퍼 시뮬레이션, 프린트 스풀러 구현 |
| `C/expert_c/ch1/` | Expert C 1장 예제 (포인터, 선언 해석 등) |
| `C++/HighendC++/` | 명품 C++ 교재 ch5~ch7 예제 및 연습문제 |
| `C++/expertC++/` | Expert C++ 학습 자료 |
| `C++/atcoder/` | [AtCoder](https://atcoder.jp/) ABC/AWC 시리즈 문제 풀이 |
| `C++/codeforces/` | [Codeforces](https://codeforces.com/) 문제 풀이 |
| `C++/forzan_cpp/` | 포르잔 C++ ch4~ch8 예제 및 실습 |

---

## 개발 환경

- **언어**: C / C++
- **에디터**: Visual Studio Code
- **컴파일러**: GCC (g++) — MinGW64
- **플랫폼**: Windows 11 64-bit

---

## 빌드 방법

```bash
# C++ 단일 파일 컴파일
g++ -std=c++17 -O2 -o solution solution.cpp

# 디버그 빌드 (VSCode Ctrl+Shift+B와 동일)
g++ -fdiagnostics-color=always -g solution.cpp -o solution.exe

# C 단일 파일 컴파일
gcc -o program program.c

# 실행
./solution.exe
```

---

## 문제풀이 현황

### AtCoder

| 문제 | 난이도 |
|------|--------|
| ABC453 B | B |
| ABC455 C | C |
| ABC456 B, C | B, C |
| ABC457 B, C, D | B, C, D |
| ABC460 A, B | A, B |
| AWC006 1A, 1B, 2A, 2B, 3A, 3B, 8 | — |
| AWC008 1A, 1B, 1C | — |

### Codeforces

| 문제 | 비고 |
|------|------|
| 50A, 71A, 112A, 158A | Div.2 A |
| 236A, 263A, 339A, 937A | Div.2 A |

---

## 학습 목표

- [ ] AtCoder D레벨 문제 독립 풀이
- [ ] Codeforces 레이팅 획득
- [ ] C++ STL 및 알고리즘 숙달
- [ ] 자료구조 (연결리스트, 트리, 큐 등) 직접 구현
- [ ] Expert C/C++ 스터디 시작
- [ ] 소켓 프로그래밍 및 게임 서버 프로그래밍

---

## 자료구조 구현 하이라이트

직접 구현한 자료구조 목록입니다.

| 구조 | 파일 | 설명 |
|------|------|------|
| 단순 연결 리스트 | `LinkedList.c` | 삽입·삭제·탐색 |
| 이중 연결 리스트 | `doubleList.c` | 양방향 순회 |
| 원형 연결 리스트 | `CircleLlist.c` | 멀티게임 플레이어 시뮬레이션 |
| 배열 스택 | `stack.c` | 기본 구현 |
| 동적 스택 | `mallocStack.c` | malloc 기반 가변 크기 |
| 선형 큐 | `queue.c` | 기본 구현 |
| 원형 큐 | `circleQueue.c` | 오버플로 방지 |
| 덱(Deque) | `deque.c` | 양방향 삽입·삭제 |

**응용 프로젝트**

| 프로젝트 | 파일 | 설명 |
|----------|------|------|
| 다항식 계산기 | `calcPoly.c`, `poly.c` | 연결 리스트 기반 다항식 덧셈 |
| 희소 행렬 | `sparseMatrix.c` | 연결 리스트로 0이 많은 행렬 표현 |
| MP3 플레이어 | `mpthree.c` | 이중 연결 리스트로 재생목록 구현 |
| 괄호 검사기 | `checkBrackets.c` | 스택으로 괄호 유효성 검사 |
| 수식 변환·계산기 | `infixToPosftfix.c`, `calcPosfix.c` | 중위→후위 변환 후 계산 |
| 은행 시뮬레이터 | `bamkSim.c`, `BankSim2Banker.c` | 큐로 창구 대기열 시뮬레이션 |
| 프린트 스풀러 | `PrintSpooler.c` | 큐 기반 출력 순서 관리 |
