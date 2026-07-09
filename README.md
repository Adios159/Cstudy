# C_STUDY

> C/C++ 알고리즘 문제풀이 및 자료구조 학습을 기록하는 저장소입니다.
> AtCoder 및 Codeforces 문제풀이, 교재 실습, 자료구조 직접 구현, 소켓 프로그래밍을 포함합니다.

![Language](https://img.shields.io/badge/language-C%2FC%2B%2B-blue)
![Platform](https://img.shields.io/badge/platform-Ubuntu%2024.04-lightgrey)
![Compiler](https://img.shields.io/badge/compiler-GCC%20(g%2B%2B)-green)
![AtCoder](https://img.shields.io/badge/AtCoder-ABC%20%7C%20AWC-orange)
![Codeforces](https://img.shields.io/badge/Codeforces-Div.4-red)

---

## 주요 특징

- **자료구조 직접 구현** — 연결 리스트·스택·큐·트리를 C로 밑바닥부터 구현, 다항식·MP3 플레이어 등 응용 프로젝트 포함
- **알고리즘 문제풀이** — AtCoder ABC/AWC, Codeforces Div.4, SPOJ, Kattis 문제를 꾸준히 풀며 실력 향상 중 (진행 상황은 [AtCoder 트래커](C++/PS/atcoder/TRACKER.md) 참고)
- **교재 병행 학습** — 명품 C++·포르잔 C++·Expert C/C++ 교재를 통해 언어 기반 다지기
- **「이것이 자료구조&알고리즘이다」 재구현** — 정렬·검색·힙·해시테이블·문자열 탐색·그래프 알고리즘과 연결리스트·스택·큐·트리 자료구조를 교재 진도에 맞춰 재구현, 분할 정복 패러다임 학습 포함
- **소켓 프로그래밍** — TCP/IP 소켓 프로그래밍 교재 기반으로 Hello World 서버/클라이언트, 저수준 파일 입출력부터 시작 (진행 중)

---

## 폴더 구조

```
C_STUDY/
├── C/                              # C 언어 학습
│   ├── DataStructure_Algorithm/    # 자료구조 & 알고리즘 직접 구현
│   │   ├── Algorithm/
│   │   │   └── ThisIsDnA/          # 이것이 자료구조&알고리즘이다 - 알고리즘
│   │   │       ├── Algorithm/
│   │   │       │   ├── sort/               # 정렬 알고리즘 (버블/삽입/퀵/qsort)
│   │   │       │   ├── search/              # 검색 알고리즘
│   │   │       │   │   ├── BasicSearch/     # 순차/이분 탐색, 전위법, MTF
│   │   │       │   │   ├── BinarySearch/    # 이분 탐색 재구현
│   │   │       │   │   └── BinarySearchTree/ # 이진 탐색 트리
│   │   │       │   ├── Heap/
│   │   │       │   │   ├── Heap/            # 배열 기반 힙
│   │   │       │   │   └── PriorityQueue/   # 힙 기반 우선순위 큐
│   │   │       │   ├── HashTable/
│   │   │       │   │   ├── BasicHash/       # 나눗셈법 기본 해싱
│   │   │       │   │   └── Chaning/         # 체이닝(연결 리스트) 해시테이블
│   │   │       │   ├── StringSearch/
│   │   │       │   │   ├── BruteForce/      # 브루트포스 문자열 탐색
│   │   │       │   │   └── KarpRabin/       # 카프-라빈 알고리즘
│   │   │       │   └── Graph/
│   │   │       │       ├── Graph/                  # 정점·인접 리스트 기반 그래프 생성/소멸
│   │   │       │       ├── GraphTravel/            # DFS/BFS 순회
│   │   │       │       ├── TopologicalSort/        # 위상 정렬
│   │   │       │       ├── MinimumSpanningTree/    # 최소 신장 트리 (Prim)
│   │   │       │       └── Dijkstra/               # 다익스트라 최단 경로
│   │   │       └── Algoruithm_paradigm/
│   │   │           └── Divide_and_Counquer/  # 분할 정복 (빠른 거듭제곱, 피보나치, 병합정렬)
│   │   ├── DataStructure/
│   │   │   ├── DatastrucureInC/    # 자료구조 직접 구현 (기존 교재 기반)
│   │   │   │   ├── LinkedList/     # 연결 리스트 (단순/이중/원형) 및 응용
│   │   │   │   ├── Stack/          # 스택 구현 및 응용
│   │   │   │   ├── queue/          # 큐 구현 및 응용
│   │   │   │   └── tree/           # 이진 트리 구현 및 응용 (순회, 디렉토리 크기, 수식 계산, 스레드 이진 트리)
│   │   │   └── ThisIsDnA/          # 이것이 자료구조&알고리즘이다 - 자료구조 (진행 중)
│   │   │       ├── LinkedList/     # 연결 리스트 재구현 (단순/이중/원형)
│   │   │       ├── Stack/          # 배열 스택, 연결 리스트 스택, 후위 표기 계산기
│   │   │       ├── Queue/          # 원형 큐, 연결 리스트 큐
│   │   │       └── Tree/           # 이진 트리, 상호배타집합, 수식 트리, LCRS 트리
│   │   ├── Headers/                # 공용 큐/스택/덱/연결 리스트 헤더 및 구현 (실습용 기반 코드)
│   │   └── Practice/               # 챕터별 잡다한 연습 코드 (ch4, ch6)
│   ├── TCP-IP/                     # 소켓 프로그래밍 학습 (진행 중)
│   │   └── ch1/
│   │       ├── hello/              # Hello World 출력 서버/클라이언트
│   │       └── low_level_fileIO/   # 저수준 파일 I/O (open/read/write, fd 직렬화)
│   └── expert_c/                   # Expert C 학습 자료
│       ├── ch1/                    # 1장 예제 코드 (C 기본문법 정리 & 전처리기 지시어)
│       ├── ch2/                    # 2장 예제 코드 (분할 컴파일, 헤더 파일 설계)
│       ├── ch3/                    # 3장 예제 코드 (다중 파일 함수 호출, 정적 라이브러리 설계)
│       ├── ch4/                    # 4장 예제 코드 (바이너리 크기 분석, 힙 세그먼트와 메모리 매핑)
│       ├── ch5/                    # 5장 예제 코드 (malloc/calloc, 메모리 누수, 디스어셈블 분석)
│       ├── ch6/                    # 6장 예제 코드 (C언어 객체지향 기초(구조체 캡슐화, 단순 리스트))
│       ├── ch7/                    # 7장 예제 코드 (불완전 타입(opaque pointer)으로 구조체 합성, has-a 관계)
│       └── ch8/                    # 8장 예제 코드 (구조체 합성으로 상속 흉내, 부모 구조체 비공개 구현 접근)
├── C++/                            # C++ 학습 및 문제풀이
│   ├── HighendC++/                 # 명품 C++ 교재 학습
│   │   ├── ch5/                    # 함수의 참조, 클래스 복사
│   │   │   ├── example/            # 예제 코드 (11개)
│   │   │   └── exercise/           # 연습문제 (7개)
│   │   ├── ch6/                    # 함수 중복과 static
│   │   │   ├── example/            # 예제 코드 (8개)
│   │   │   └── exercise/           # 연습문제 (6개)
│   │   ├── ch7/                    # friend, 연산자 중복
│   │   │   ├── example/            # 예제 코드 (10개)
│   │   │   └── exercise/           # 연습문제 (6개)
│   │   ├── ch8/                    # 상속
│   │   │   ├── example/            # 예제 코드 (4개)
│   │   │   └── exercise/           # 연습문제 (5개)
│   │   ├── ch9/                    # 가상 함수와 추상 클래스
│   │   │   ├── example/            # 예제 코드 (7개)
│   │   │   └── exercise/           # 연습문제 (2개)
│   │   ├── ch10/                   # 템플릿과 STL
│   │   │   └── example/            # 예제 코드 (12개)
│   │   └── ch11/                   # 표준 템플릿 라이브러리 STL
│   │       └── example/            # 예제 코드 (3개)
│   ├── coding_test(prePS)/         # PS 입문 코딩테스트 연습
│   │   └── array/                  # 배열 유형 문제
│   ├── PS/                         # 알고리즘 문제풀이
│   │   ├── atcoder/                # AtCoder 문제풀이
│   │   │   ├── TRACKER.md          # AtCoder 풀이 트래커 (대회/문제/날짜/복습 여부/메모)
│   │   │   ├── abc/                # ABC 시리즈 (대회별 하위 폴더)
│   │   │   └── awc/                # AWC 시리즈 (대회별 하위 폴더)
│   │   ├── codeforces/             # Codeforces 문제풀이
│   │   │   ├── TRACKER.md          # Codeforces 풀이 트래커
│   │   │   └── unknowned/          # 대회 미상 문제 풀이
│   │   ├── SPOJ/                   # SPOJ 문제풀이
│   │   │   └── before 1000s/       # 1000번 이전 문제
│   │   └── kattis/                 # Kattis 문제풀이
│   └── forzan_cpp/                 # 포르잔 C++ 학습 코드
│       ├── ch4/                    # ch4 예제
│       ├── ch5/                    # ch5 예제
│       └── ch8/                    # 파일 I/O, 다중 파일 클래스 설계
├── CLAUDE.md
├── .gitignore
└── README.md
```

---

## 디렉토리 설명

| 폴더 | 설명 |
|------|------|
| `C/DataStructure_Algorithm/DataStructure/DatastrucureInC/LinkedList/` | 단순/이중/원형 연결 리스트, 문자열·큐·스택 응용, 다항식·희소행렬·MP3 시뮬레이션 등 구현 |
| `C/DataStructure_Algorithm/DataStructure/DatastrucureInC/Stack/` | 배열·동적 스택 구현, 괄호 검사, 중위→후위 변환, 후위 계산, 브라우저 뒤로/앞으로가기 시뮬레이션 |
| `C/DataStructure_Algorithm/DataStructure/DatastrucureInC/queue/` | 선형·원형 큐, 덱, 은행·콜센터·버퍼 시뮬레이션, 프린트 스풀러 구현 |
| `C/DataStructure_Algorithm/DataStructure/DatastrucureInC/tree/` | 이진 트리 구현, 전위·중위·후위·레벨 순회, 디렉토리 크기 계산, 수식 트리 계산, 스레드 이진 트리 |
| `C/DataStructure_Algorithm/DataStructure/ThisIsDnA/` | 「이것이 자료구조&알고리즘이다」 자료구조 재구현 (LinkedList(단순/이중/원형), Stack(배열/연결 리스트/계산기), Queue(원형/연결 리스트), Tree(이진 트리/상호배타집합/수식 트리/LCRS 트리), 진행 중) |
| `C/DataStructure_Algorithm/Algorithm/ThisIsDnA/Algorithm/sort/` | 「이것이 자료구조&알고리즘이다」 정렬 알고리즘 (버블, 삽입, 퀵, `qsort`) |
| `C/DataStructure_Algorithm/Algorithm/ThisIsDnA/Algorithm/search/` | 「이것이 자료구조&알고리즘이다」 검색 알고리즘 (순차/이분 탐색, 전위법, Move-To-Front, 이진 탐색 트리) |
| `C/DataStructure_Algorithm/Algorithm/ThisIsDnA/Algorithm/Heap/` | 「이것이 자료구조&알고리즘이다」 힙, 우선순위 큐 |
| `C/DataStructure_Algorithm/Algorithm/ThisIsDnA/Algorithm/HashTable/` | 「이것이 자료구조&알고리즘이다」 해싱 (나눗셈법 기본 해싱, 체이닝) |
| `C/DataStructure_Algorithm/Algorithm/ThisIsDnA/Algorithm/StringSearch/` | 「이것이 자료구조&알고리즘이다」 문자열 탐색 (브루트포스, 카프-라빈) |
| `C/DataStructure_Algorithm/Algorithm/ThisIsDnA/Algorithm/Graph/` | 「이것이 자료구조&알고리즘이다」 그래프 구현, DFS/BFS 순회, 위상정렬, 최소신장트리(Prim), 다익스트라 최단 경로 |
| `C/DataStructure_Algorithm/Algorithm/ThisIsDnA/Algoruithm_paradigm/Divide_and_Counquer/` | 「이것이 자료구조&알고리즘이다」 분할 정복 (빠른 거듭제곱, 피보나치, 병합정렬) |
| `C/DataStructure_Algorithm/Headers/` | 큐·스택·덱·연결 리스트 공용 헤더 및 구현 (실습용 기반 코드) |
| `C/DataStructure_Algorithm/Practice/` | 챕터별(ch4, ch6) 잡다한 연습 코드 |
| `C/TCP-IP/ch1/hello/` | Hello World 출력 소켓 서버/클라이언트 (`hello_server.c`, `hello_client.c`) |
| `C/TCP-IP/ch1/low_level_fileIO/` | 저수준 파일 입출력 (`open`/`read`/`write` 시스템 콜, 파일 디스크립터 직렬화) |
| `C/expert_c/ch1/` | Expert C 1장 예제 (C언어 기초 복습) |
| `C/expert_c/ch2/` | Expert C 2장 예제 (분할 컴파일, 헤더 파일·다중 파일 함수 선언 설계) |
| `C/expert_c/ch3/` | Expert C 3장 예제 (다중 파일 함수 호출, 2D/3D 극좌표-직교좌표 변환 정적 라이브러리) |
| `C/expert_c/ch4/` | Expert C 4장 예제 (`size` 명령으로 바이너리 text/data/bss 크기 분석, 힙 세그먼트와 `/proc/self/maps` 메모리 매핑) |
| `C/expert_c/ch5/` | Expert C 5장 예제 (malloc/calloc 메모리 할당, 메모리 누수 추적, objdump 디스어셈블 분석) |
| `C/expert_c/ch6/` | Expert C 6장 예제 (구조체 기반 캡슐화(car), 헤더 파일로 분리한 연결 리스트 모듈, 전처리/디스어셈블 결과 비교) |
| `C/expert_c/ch7/` | Expert C 7장 예제 (불완전 타입으로 구현체 은닉, car-engine·player-gun has-a 관계 합성) |
| `C/expert_c/ch8/` | Expert C 8장 예제 (구조체 합성으로 상속 흉내(student가 person 포함), 캐스팅으로 부모 구조체 비공개 구현에 접근) |
| `C++/HighendC++/` | 명품 C++ 교재 ch5~ch11 예제 및 연습문제 |
| `C++/HighendC++/ch8/` | 상속 (예제 4개, 연습문제 5개) |
| `C++/HighendC++/ch9/` | 가상 함수와 추상 클래스 (예제 7개, 연습문제 2개) |
| `C++/HighendC++/ch10/` | 템플릿과 STL (예제 12개) |
| `C++/HighendC++/ch11/` | 표준 템플릿 라이브러리 STL (예제 3개) |
| `C++/coding_test(prePS)/` | PS 입문 전 코딩테스트 유형별 연습 |
| `C++/PS/atcoder/abc/` | [AtCoder](https://atcoder.jp/) ABC 시리즈 문제 풀이 (대회별 하위 폴더) |
| `C++/PS/atcoder/awc/` | [AtCoder](https://atcoder.jp/) AWC 시리즈 문제 풀이 (대회별 하위 폴더) |
| `C++/PS/atcoder/TRACKER.md` | AtCoder 풀이 트래커 (문제·풀이 날짜·복습 필요 여부·메모) |
| `C++/PS/codeforces/` | [Codeforces](https://codeforces.com/) 문제 풀이 |
| `C++/PS/codeforces/TRACKER.md` | Codeforces 풀이 트래커 (틀만 준비, 채워나가는 중) |
| `C++/PS/codeforces/unknowned/` | 대회 미상 Codeforces 문제 풀이 |
| `C++/PS/SPOJ/before 1000s/` | [SPOJ](https://www.spoj.com/) 1000번 이전 문제 풀이 |
| `C++/PS/kattis/` | [Kattis](https://open.kattis.com/) 문제 풀이 |
| `C++/forzan_cpp/` | 포르잔 C++ ch4~ch8 예제 및 실습 |

---

## 개발 환경

- **언어**: C / C++
- **에디터**: Visual Studio Code
- **컴파일러**: GCC (g++)
- **플랫폼**: Ubuntu 24.04

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

> 문제별 풀이 날짜, 복습 필요 여부, 메모 등 상세 기록은 [AtCoder 트래커](C++/PS/atcoder/TRACKER.md) / [Codeforces 트래커](C++/PS/codeforces/TRACKER.md) 참고.

### AtCoder

**ABC** (13개 대회, 33문제)

| 대회 | 풀이 문제 |
|------|-----------|
| ABC440 | A, B |
| ABC453 | A, B |
| ABC455 | C |
| ABC456 | B, C |
| ABC457 | B, C, D |
| ABC458 | A, B, C, D |
| ABC459 | A, B |
| ABC460 | A, B, C |
| ABC461 | A, B |
| ABC462 | A, B, C |
| ABC463 | A, B, C |
| ABC464 | A, B, C |
| ABC465 | A, B, C |

**AWC** (9개 대회, 19문제)

| 대회 | 풀이 문제 |
|------|-----------|
| AWC0061 | A, B |
| AWC0062 | A, B |
| AWC0063 | A, B |
| AWC0064 | A, B, C |
| AWC0068 | A, B |
| AWC0079 | A |
| AWC0081 | A, B, C |
| AWC0103 | A, B |
| AWC0104 | A, B |

### Codeforces

| 문제 | 비고 |
|------|------|
| 50A, 71A, 112A, 158A | Div.2 A |
| 236A, 263A, 339A, 937A | Div.2 A |

### SPOJ / Kattis

| 사이트 | 문제 | 비고 |
|--------|------|------|
| [SPOJ](https://www.spoj.com/) | 74 | 약수의 합 (에라토스테네스 체 응용) |
| [Kattis](https://open.kattis.com/) | 99 Problems, lv_able | 문자열/구현 문제 |

---

## 학습 목표

- [ ] AtCoder D레벨 문제 독립 풀이
- [ ] Codeforces 레이팅 획득
- [ ] C++ STL 및 알고리즘 숙달
- [x] 자료구조 (연결리스트, 트리, 큐 등) 직접 구현
- [x] Expert C/C++ 스터디 시작
- [x] 정렬·검색·힙·해시테이블·문자열탐색·그래프(DFS/BFS, 위상정렬, 최소신장트리, 다익스트라) 알고리즘 직접 구현
- [ ] 소켓 프로그래밍 및 게임 서버 프로그래밍 (Hello World 서버, 저수준 파일 I/O부터 시작)

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
| 수식 변환·계산기 | `infixToPostfix.c`, `calcPosfix.c` | 중위→후위 변환 후 계산 |
| 은행 시뮬레이터 | `bankSim.c`, `BankSim2Banker.c` | 큐로 창구 대기열 시뮬레이션 |
| 콜센터 시뮬레이터 | `callCenter.c` | 덱으로 상담원 대기열 시뮬레이션 |
| 버퍼 시뮬레이터 | `bufferSim.c` | 큐로 데이터 버퍼링 시뮬레이션 |
| 프린트 스풀러 | `PrintSpooler.c` | 큐 기반 출력 순서 관리 |
| 브라우저 시뮬레이터 | `browserSim.c` | 스택으로 뒤로가기/앞으로가기 구현 |

**트리(Tree) 구현**

| 구조/응용 | 파일 | 설명 |
|-----------|------|------|
| 이진 트리 (정적 노드) | `tree.c` | 전위·중위·후위 순회 |
| 이진 트리 (동적 할당) | `tree_node.c` | malloc 기반 노드 생성·해제 |
| 이진 트리 순회 정리 | `ordering_tree.c` | 전위·중위·후위 순회 함수 정리 |
| 반복적 중위 순회 | `inorder_with_stack.c` | 스택을 이용한 비재귀 중위 순회 |
| 레벨 순회 (BFS) | `level_order.c` | 큐 기반 레벨 단위 순회 |
| 디렉토리 크기 계산기 | `calc_dir.c` | 트리 재귀로 하위 노드 크기 합산 |
| 수식 트리 계산기 | `calc_expression.c` | 연산자/피연산자 트리 재귀 평가 |
| 스레드 이진 트리 | `thread_binary_tree.c` | 스레드로 후속자(successor) 탐색, 스택 없이 중위 순회 |

**「이것이 자료구조&알고리즘이다」 재구현** (`DataStructure/ThisIsDnA/`)

| 구조 | 파일 | 설명 |
|------|------|------|
| 단순 연결 리스트 | `LinkedList/LinkedList/linked_list.c` | 삽입·삭제·탐색 재구현 |
| 원형 연결 리스트 | `LinkedList/CircleList/CircleList.c` | 원형 구조 재구현 |
| 이중 연결 리스트 | `LinkedList/DList/DList.c` | 양방향 순회 재구현 |
| 배열 스택 | `Stack/ArrayStack/ArrayStack.c` | 배열 기반 스택 재구현 |
| 연결 리스트 스택 | `Stack/LinkedListStack/LinkedListStack.c` | 연결 리스트 기반 스택 재구현 |
| 계산기 | `Stack/Calculator/Calculator.c` | 연결 리스트 스택으로 사칙연산 수식 계산 |
| 원형 큐 | `Queue/CircularQueue/CircularQueue.c` | 배열 기반 원형 큐 재구현 |
| 연결 리스트 큐 | `Queue/LinkedQueue/LinkedQueue.c` | 연결 리스트 기반 큐 재구현 |
| 이진 트리 | `Tree/BinaryTree/BinaryTree.c` | 노드 생성·삭제, 순회 재구현 |
| 상호배타집합(Disjoint Set) | `Tree/DisjointSet/DisjointSet.c` | Union-Find (합집합-찾기) 구현 |
| 수식 트리 | `Tree/ExpressionTree/ExpressionTree.c` | 연산자/피연산자 트리로 수식 표현 및 평가 |
| LCRS 트리 | `Tree/LCRSTree/LCRSTree.c` | Left-Child Right-Sibling 표현법으로 일반 트리 구현 |

---

## 알고리즘 구현 하이라이트

「이것이 자료구조&알고리즘이다」 교재 기반으로 직접 구현한 정렬·검색·힙·해시·문자열탐색·그래프·분할정복 알고리즘입니다.

**정렬(Sort)**

| 알고리즘 | 파일 | 설명 |
|----------|------|------|
| 버블 정렬 | `BubbleSort.c` | 인접 원소 비교 후 교환 |
| 삽입 정렬 | `InsertionSort.c` | `memmove`로 삽입 위치 확보 |
| 퀵 정렬 | `QuichSort.c` | 피벗 기반 분할 정복 |
| 표준 라이브러리 정렬 | `Qsort.c` | C 표준 `qsort` 비교 함수 활용 |

**검색(Search)**

| 알고리즘 | 파일 | 설명 |
|----------|------|------|
| 순차 검색 | `BasicSearch/sequential_search.c` | 연결 리스트를 처음부터 순회하며 탐색 |
| 이분 검색 | `BasicSearch/binary_search.c` | 정렬된 배열에서 절반씩 탐색 범위 축소 |
| 전위법 검색 | `BasicSearch/transpose.c` | 검색된 노드를 한 칸씩 앞으로 이동시켜 재검색 속도 개선 |
| MTF(Move-To-Front) | `BasicSearch/MoveToFront.c` | 검색된 노드를 리스트 맨 앞으로 이동시켜 재검색 속도 개선 |
| 이분 검색 재구현 | `BinarySearch/binarysearch.c`, `bsearch.c` | 좌표(point) 구조체를 대상으로 이분 검색 재구현 |
| 이진 탐색 트리 | `BinarySearchTree/BinarySearchTree.c` | 삽입·탐색·삭제, 재귀 기반 노드 관리 |

**힙(Heap) / 우선순위 큐**

| 구조 | 파일 | 설명 |
|------|------|------|
| 힙 | `Heap/heap.c` | 배열 기반 최대 힙, 삽입 시 상향 재구성 |
| 우선순위 큐 | `PriorityQueue/PriorityQueue.c` | 힙을 이용한 우선순위 큐 구현 |

**해시 테이블(Hash Table)**

| 구조 | 파일 | 설명 |
|------|------|------|
| 기본 해싱 | `BasicHash/BasicHash.c` | 나눗셈법 기반 해시 함수 |
| 체이닝 | `Chaning/Chaining.c` | 연결 리스트로 충돌을 처리하는 해시 테이블 |

**문자열 탐색(String Search)**

| 알고리즘 | 파일 | 설명 |
|----------|------|------|
| 브루트포스 | `StringSearch/BruteForce/BruteForce.c` | 패턴을 한 칸씩 이동하며 전수 비교 |
| 카프-라빈(Karp-Rabin) | `StringSearch/KarpRabin/KarpRabin.c` | 해시값 비교로 패턴 매칭 후보를 빠르게 선별 |

**그래프(Graph)**

| 구조/알고리즘 | 파일 | 설명 |
|---------------|------|------|
| 그래프 구현 | `Graph/Graph/graph.c` | 정점·인접 리스트 기반 그래프 생성/소멸 |
| 깊이 우선 탐색(DFS) | `Graph/GraphTravel/GraphTravel.c` | 재귀 기반 깊이 우선 탐색 |
| 너비 우선 탐색(BFS) | `Graph/GraphTravel/GraphTravel.c` | 연결 리스트 큐 기반 너비 우선 탐색 |
| 위상 정렬(Topological Sort) | `Graph/TopologicalSort/TopologicalSort.c` | 진입 차수(in-degree) 기반 큐 반복 정렬 |
| 최소 신장 트리(MST, Prim) | `Graph/MinimumSpanningTree/MST.c` | 우선순위 큐로 최소 간선을 선택해 확장하는 Prim 알고리즘 |
| 다익스트라(Dijkstra) | `Graph/Dijkstra/ShortestPath.c` | 우선순위 큐 기반 최단 경로 탐색 |

**분할 정복(Divide and Conquer)**

| 알고리즘 | 파일 | 설명 |
|----------|------|------|
| 빠른 거듭제곱 | `Algoruithm_paradigm/Divide_and_Counquer/FastExponentiation.c` | 지수를 절반씩 나누어 O(log n)에 거듭제곱 계산 |
| 피보나치 | `Algoruithm_paradigm/Divide_and_Counquer/Fibonacci.c` | 분할 정복 방식으로 피보나치 수 계산 |
| 병합 정렬 | `Algoruithm_paradigm/Divide_and_Counquer/MergeSort.c` | 배열을 절반으로 분할 후 정렬하며 병합 |
