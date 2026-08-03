# C_STUDY

> C/C++ 알고리즘 문제풀이 및 자료구조 학습을 기록하는 저장소입니다.
> AtCoder 및 Codeforces 문제풀이, 교재 실습, 자료구조 직접 구현, 소켓 프로그래밍을 포함합니다.

![Language](https://img.shields.io/badge/language-C%2FC%2B%2B-blue)
![Platform](https://img.shields.io/badge/platform-Ubuntu%2024.04-lightgrey)
![Compiler](https://img.shields.io/badge/compiler-GCC%20(g%2B%2B)-green)
![AtCoder](https://img.shields.io/badge/AtCoder-ABC%20%7C%20AWC-orange)
![Codeforces](https://img.shields.io/badge/Codeforces-Div.2%20%7C%20Div.3-red)

---

## 주요 특징

- **자료구조 직접 구현** — 연결 리스트·스택·큐·트리를 C로 밑바닥부터 구현
- **알고리즘 문제풀이** — AtCoder ABC/AWC, Codeforces Div.2/Div.3, SPOJ, Kattis 문제풀 (진행 상황은 [AtCoder 트래커](C++/PS/contest/atcoder/TRACKER.md) / [Codeforces 트래커](C++/PS/contest/codeforces/TRACKER.md) 참고)
- **교재 병행 학습** — 명품 C++·포르잔 C++(C++ 기초)·Expert C/C++ 교재를 통해 언어 기반 다지기 (잠정 중단)
- **「이것이 자료구조&알고리즘이다」 재구현** — 정렬·검색·힙·해시테이블·문자열 탐색·그래프 알고리즘과 연결리스트·스택·큐·트리 자료구조를 교재 진도에 맞춰 재구현, 분할 정복·동적 계획법 패러다임 학습 포함
- **소켓 프로그래밍** — 윤성우의 열혈 TCP/IP 소켓 프로그래밍 교재 공부
- **CLRS 스터디** — CLRS(Introduction to Algorithms) 스터디, 삽입 정렬부터 재구현
- **실전 알고리즘 스터디** — PS를 위한 알고리즘과 계산량(1장), 누적합(2장), 이진 탐색(3장), 동적 계획법(4장), 수학적 문제(5장) 개념 정리 및 예제·연습문제 풀이 (진행 중)

---

## 폴더 구조

```
C_STUDY/
├── C/                              # C 언어 학습
│   ├── DSA/                         # 자료구조 & 알고리즘 직접 구현
│   │   ├── Algorithm/
│   │   │   ├── ThisIsDnA/          # 이것이 자료구조&알고리즘이다 - 알고리즘
│   │   │   │   ├── Algorithm/
│   │   │   │   │   ├── sort/               # 정렬 알고리즘 (버블/삽입/퀵/qsort)
│   │   │   │   │   ├── search/              # 검색 알고리즘
│   │   │   │   │   │   ├── BasicSearch/     # 순차/이분 탐색, 전위법, MTF
│   │   │   │   │   │   ├── BinarySearch/    # 이분 탐색 재구현
│   │   │   │   │   │   └── BinarySearchTree/ # 이진 탐색 트리
│   │   │   │   │   ├── Heap/
│   │   │   │   │   │   ├── Heap/            # 배열 기반 힙
│   │   │   │   │   │   └── PriorityQueue/   # 힙 기반 우선순위 큐
│   │   │   │   │   ├── HashTable/
│   │   │   │   │   │   ├── BasicHash/       # 나눗셈법 기본 해싱
│   │   │   │   │   │   └── Chaning/         # 체이닝(연결 리스트) 해시테이블
│   │   │   │   │   ├── StringSearch/
│   │   │   │   │   │   ├── BruteForce/      # 브루트포스 문자열 탐색
│   │   │   │   │   │   └── KarpRabin/       # 카프-라빈 알고리즘
│   │   │   │   │   └── Graph/
│   │   │   │   │       ├── Graph/                  # 정점·인접 리스트 기반 그래프 생성/소멸
│   │   │   │   │       ├── GraphTravel/            # DFS/BFS 순회
│   │   │   │   │       ├── TopologicalSort/        # 위상 정렬
│   │   │   │   │       ├── MinimumSpanningTree/    # 최소 신장 트리 (Prim)
│   │   │   │   │       └── Dijkstra/               # 다익스트라 최단 경로
│   │   │   │   └── Algoruithm_paradigm/
│   │   │   │       ├── Divide_and_Counquer/  # 분할 정복 (빠른 거듭제곱, 피보나치, 병합정렬)
│   │   │   │       └── Dynamic_Programming/  # 동적 계획법 (피보나치, LCS - DC/DP 방식)
│   │   │   └── CLRS/                # CLRS(Introduction to Algorithms) 재구현
│   │   │       └── ch2/             # 2장 (삽입 정렬)
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
│   │   ├── Headers/                # 공용 자료구조 헤더 및 구현, Makefile 빌드 (실습용 기반 코드)
│   │   │   ├── Datastructure/          # 스택/큐/덱, 연결 리스트(단순/이중/원형)
│   │   │   └── utils/                  # 공용 유틸리티 (랜덤 생성기 등)
│   │   └── Practice/               # 챕터별 잡다한 연습 코드 (ch4, ch6, ch7)
│   ├── TCP-IP/                     # 소켓 프로그래밍 학습 (진행 중)
│   │   ├── ch1/
│   │   ├── ch2/                    # 프로토콜 개념, TCP 에코 서버/클라이언트
│   │   ├── ch3/                    # 주소체계(IP/IPv4/포트)와 데이터 정렬(엔디안 변환, inet 함수)
│   │   ├── ch4/                    # TCP 프로토콜 스택 정리, 반복적(iterative) 에코 서버/클라이언트
│   │   ├── ch5/                    # TCP 입출력 버퍼·연결 이론 정리, 기존 에코 클라이언트 문제점과 반복 수신(op_client/op_server)
│   │   ├── ch6/                    # UDP 개념 정리, UDP 에코 서버/클라이언트, 소켓 주소 바인딩
│   │   ├── ch7/                    # half-close 개념 정리, 파일 송수신 서버/클라이언트(shutdown 활용)
│   │   ├── ch8/                    # DNS 개념 정리, gethostbyname/gethostbyaddr
│   │   ├── ch9/                    # 소켓 옵션 정리, 소켓 타입·버퍼 크기 조회/설정, SO_REUSEADDR 에코 서버/클라이언트
│   │   ├── ch10/                   # 멀티프로세스 개념 정리, fork/wait/waitpid, 좀비 프로세스, 시그널(signal/sigaction)로 좀비 제거, 멀티프로세스 반복 에코 서버/클라이언트
│   │   ├── ch11/                   # 프로세스간 통신(IPC), 파이프(pipe) 기반 통신, 에코 스토어 서버
│   │   ├── ch12/                   # IO 멀티플렉싱 개념 정리, select 함수, select 기반 에코 서버
│   │   ├── ch13/                   # 다양한 입출력 함수, OOB(긴급 데이터), MSG_PEEK, readv/writev
│   │   ├── ch14/                   # 멀티캐스트·브로드캐스트 개념, 뉴스 송수신 서버/클라이언트
│   │   ├── ch15/                   # 소켓과 표준 입출력, FILE 스트림 기반 에코 서버/클라이언트
│   │   ├── ch16/                   # 입출력 스트림의 분리, dup를 이용한 읽기/쓰기 스트림 분할
│   │   ├── ch17/                   # IO 멀티플렉싱 개선, epoll 기반 에코 서버 (LT/ET 방식)
│   │   └── ch18/                   # 멀티스레딩, mutex/semaphore 기반 동기화
│   └── expert_c/                   # Expert C 학습 자료
│       ├── ch1/                    # 1장 예제 코드 (C 기본문법 정리 & 전처리기 지시어)
│       ├── ch2/                    # 2장 예제 코드 (분할 컴파일, 헤더 파일 설계)
│       ├── ch3/                    # 3장 예제 코드 (다중 파일 함수 호출, 정적 라이브러리 설계)
│       ├── ch4/                    # 4장 예제 코드 (바이너리 크기 분석, 힙 세그먼트와 메모리 매핑)
│       ├── ch5/                    # 5장 예제 코드 (malloc/calloc, 메모리 누수, 디스어셈블 분석)
│       ├── ch6/                    # 6장 예제 코드 (C언어 객체지향 기초(구조체 캡슐화, 단순 리스트))
│       ├── ch7/                    # 7장 예제 코드 (불완전 타입(opaque pointer)으로 구조체 합성, has-a 관계)
│       ├── ch8/                    # 8장 예제 코드 (구조체 합성 상속, 부모 구조체 포인터 캐스팅, 다형성)
│       ├── ch10/                   # 10장 예제 코드 (시스템 콜, truss로 시스템 콜 추적)
│       └── ch12/                   # 12장 예제 코드 (C11 문법: __STDC_VERSION__, _Generic 제네릭 매크로, 익명 구조체/공용체)
├── C++/                            # C++ 학습 및 문제풀이
│   ├── expert_C++/                 # Expert C++ 교재 학습 (진행 중)
│   │   ├── ch1/                    # 1장 예제 코드 (C++ 기초 문법 복습)
│   │   ├── ch2/                    # 2장 예제 코드 (문자열 다루기: cstring, string, format, string_view, charconv)
│   │   ├── ch3/                    # 3장 정리 (코딩 스타일: 주석, 함수/파일 분해, 네이밍)
│   │   ├── ch4/                    # 4장 (코드 없음, 개념 정리만 진행)
│   │   ├── ch5/                    # 5장 (코드 없음, 개념 정리만 진행)
│   │   ├── ch6/                    # 6장 (코드 없음, 개념 정리만 진행)
│   │   └── ch7/                    # 7장 (진행 예정, 빈 폴더)
│   ├── C++basic/                   # 기초 문법 다지기 교재 모음
│   │   ├── HighendC++/             # 명품 C++ 교재 학습
│   │   │   ├── ch5/                    # 함수의 참조, 클래스 복사
│   │   │   ├── ch6/                    # 함수 중복과 static
│   │   │   ├── ch7/                    # friend, 연산자 중복
│   │   │   ├── ch8/                    # 상속
│   │   │   ├── ch9/                    # 가상 함수와 추상 클래스
│   │   │   ├── ch10/                   # 템플릿과 STL
│   │   │   └── ch11/                   # 표준 템플릿 라이브러리 STL
│   │   └── forzan_cpp/             # 포르잔 C++ 학습 코드
│   │       ├── ch4/                    # ch4 예제
│   │       ├── ch5/                    # ch5 예제
│   │       ├── ch8/                    # 파일 I/O, 다중 파일 클래스 설계
│   │       └── ch9/                    # 참조(reference) 변수 복습
│   └── PS/                         # 알고리즘 문제풀이
│       ├── algorithm_for_PS/        # 실전 알고리즘 교재 예제·연습문제
│       ├── contest/                 # 대회 문제풀이
│       │   ├── atcoder/                # AtCoder 문제풀이
│       │   │   ├── TRACKER.md          # AtCoder 풀이 트래커 (대회/문제/날짜/복습 여부/메모)
│       │   │   ├── abc/                # ABC 시리즈 (대회별 하위 폴더)
│       │   │   └── awc/                # AWC 시리즈 (대회별 하위 폴더)
│       │   └── codeforces/             # Codeforces 문제풀이
│       │       ├── TRACKER.md          # Codeforces 풀이 트래커
│       │       ├── Div2/               # Div.2 라운드 문제 풀이 (대회별 하위 폴더)
│       │       ├── Div3/               # Div.3 라운드 문제 풀이 (대회별 하위 폴더)
│       │       └── unknowned/          # 대회 미상 문제 풀이
│       └── justProblems/               # 대회 외 문제풀이
│           ├── SPOJ/                   # SPOJ 문제풀이
│           │   └── before 1000s/      # 1000번 이전 문제
│           └── kattis/                 # Kattis 문제풀이
├── testdata/           # expert_c/DSA 실습에서 참조하는 공용 테스트 데이터·바이너리 분석 산출물
├── CLAUDE.md
├── clean_build.sh      # 하위 폴더의 컴파일 산출물(오브젝트/실행 파일)을 재귀적으로 정리하는 스크립트
├── .gitignore
└── README.md
```

---

## 디렉토리 설명

| 폴더 | 설명 |
|------|------|
| `C/DSA/DataStructure/DatastrucureInC/LinkedList/` | 단순/이중/원형 연결 리스트, 다항식·희소행렬·MP3 시뮬레이션 |
| `C/DSA/DataStructure/DatastrucureInC/Stack/` | 배열·동적 스택, 괄호 검사, 중위→후위 변환·계산, 브라우저 시뮬레이션 |
| `C/DSA/DataStructure/DatastrucureInC/queue/` | 선형·원형 큐, 덱, 은행·콜센터·버퍼 시뮬레이션, 프린트 스풀러 |
| `C/DSA/DataStructure/DatastrucureInC/tree/` | 이진 트리, 순회, 디렉토리 크기 계산, 수식 트리 계산, 스레드 이진 트리 |
| `C/DSA/DataStructure/ThisIsDnA/` | 「이것이 자료구조&알고리즘이다」 자료구조 재구현 (연결 리스트, 스택, 큐, 트리) |
| `C/DSA/Algorithm/ThisIsDnA/Algorithm/sort/` | 정렬 알고리즘 (버블, 삽입, 퀵, `qsort`) |
| `C/DSA/Algorithm/ThisIsDnA/Algorithm/search/` | 검색 알고리즘 (순차/이분 탐색, 전위법, MTF, 이진 탐색 트리) |
| `C/DSA/Algorithm/ThisIsDnA/Algorithm/Heap/` | 힙, 우선순위 큐 |
| `C/DSA/Algorithm/ThisIsDnA/Algorithm/HashTable/` | 해싱 (나눗셈법, 체이닝) |
| `C/DSA/Algorithm/ThisIsDnA/Algorithm/StringSearch/` | 문자열 탐색 (브루트포스, 카프-라빈) |
| `C/DSA/Algorithm/ThisIsDnA/Algorithm/Graph/` | 그래프, DFS/BFS, 위상정렬, 최소신장트리(Prim), 다익스트라 |
| `C/DSA/Algorithm/ThisIsDnA/Algoruithm_paradigm/Divide_and_Counquer/` | 분할 정복 (빠른 거듭제곱, 피보나치, 병합정렬) |
| `C/DSA/Algorithm/ThisIsDnA/Algoruithm_paradigm/Dynamic_Programming/` | 동적 계획법 (피보나치, LCS - 분할정복/DP 비교) |
| `C/DSA/Algorithm/CLRS/ch2/` | CLRS 2장 재구현 (삽입 정렬) |
| `C/DSA/Headers/` | 큐·스택·덱·연결 리스트 공용 헤더, Makefile 빌드 (실습용 기반 코드) |
| `C/DSA/Practice/` | 챕터별(ch4, ch6, ch7) 연습 코드 |
| `C/TCP-IP/ch1/hello/` | Hello World 소켓 서버/클라이언트 |
| `C/TCP-IP/ch1/low_level_fileIO/` | 저수준 파일 입출력 (`open`/`read`/`write`) |
| `C/TCP-IP/ch2/` | 프로토콜 개념, TCP 에코 서버/클라이언트 |
| `C/TCP-IP/ch3/` | 주소체계·데이터 정렬(엔디안), `inet` 함수 구현 |
| `C/TCP-IP/ch4/` | TCP/IP 스택 정리, 반복적(iterative) 에코 서버/클라이언트 |
| `C/TCP-IP/ch5/` | TCP 입출력 버퍼 정리, 반복 수신 에코 서버/클라이언트 |
| `C/TCP-IP/ch6/` | UDP 개념, UDP 에코 서버/클라이언트, 소켓 주소 바인딩 |
| `C/TCP-IP/ch7/` | half-close 개념, 파일 송수신 서버/클라이언트 |
| `C/TCP-IP/ch8/` | DNS 개념, `gethostbyname`/`gethostbyaddr` |
| `C/TCP-IP/ch9/` | 소켓 옵션 정리, 버퍼 크기 조회/설정, `SO_REUSEADDR` 에코 서버/클라이언트 |
| `C/TCP-IP/ch10/` | 멀티프로세스 개념, `fork`/`wait`/`waitpid`, 시그널 기반 좀비 제거, 멀티프로세스 에코 서버/클라이언트 |
| `C/TCP-IP/ch11/` | 프로세스간 통신(IPC), 파이프(`pipe`) 기반 통신, 에코 스토어 서버 |
| `C/TCP-IP/ch12/` | IO 멀티플렉싱, `select` 함수, select 기반 에코 서버 |
| `C/TCP-IP/ch13/` | OOB(긴급 데이터), `MSG_PEEK`, `readv`/`writev` |
| `C/TCP-IP/ch14/` | 멀티캐스트·브로드캐스트, 뉴스 송수신 서버/클라이언트 |
| `C/TCP-IP/ch15/` | 소켓과 표준 입출력, `FILE` 스트림 기반 에코 서버/클라이언트 |
| `C/TCP-IP/ch16/` | 입출력 스트림 분리, `dup`를 이용한 읽기/쓰기 스트림 분할 |
| `C/TCP-IP/ch17/` | IO 멀티플렉싱 개선, `epoll` 기반 에코 서버 (LT/ET 방식) |
| `C/TCP-IP/ch18/` | 멀티스레딩, `mutex`/`semaphore` 기반 동기화 |
| `C/expert_c/ch1/` | 1장 예제 (C언어 기초 복습) |
| `C/expert_c/ch2/` | 2장 예제 (분할 컴파일, 헤더 파일 설계) |
| `C/expert_c/ch3/` | 3장 예제 (다중 파일 함수 호출, 정적 라이브러리) |
| `C/expert_c/ch4/` | 4장 예제 (바이너리 크기 분석, 힙 세그먼트/메모리 매핑) |
| `C/expert_c/ch5/` | 5장 예제 (malloc/calloc, 메모리 누수, 디스어셈블 분석) |
| `C/expert_c/ch6/` | 6장 예제 (구조체 캡슐화, 헤더로 분리한 연결 리스트 모듈) |
| `C/expert_c/ch7/` | 7장 예제 (불완전 타입으로 구현체 은닉, has-a 관계 합성) |
| `C/expert_c/ch8/` | 8장 예제 (구조체 합성 상속, 포인터 캐스팅, 다형성) |
| `C/expert_c/ch10/` | 10장 예제 (시스템 콜, `truss` 추적) |
| `C/expert_c/ch12/` | 12장 예제 (C11 문법: `_Generic`, 익명 구조체/공용체) |
| `C++/expert_C++/ch1/` | 1장 예제 (C++ 기초 문법 복습, 진행 중) |
| `C++/expert_C++/ch2/` | 2장 예제 (문자열 다루기: `string`/`string_view`, `format`, `charconv`) |
| `C++/expert_C++/ch3/` | 3장 정리 (코딩 스타일: 주석 작성법, 함수/파일 분해, 네이밍 규칙) |
| `C++/expert_C++/ch4~ch6/` | 4~6장 (코드 없이 개념만 정리) |
| `C++/expert_C++/ch7/` | 7장 (진행 예정, 빈 폴더) |
| `C++/C++basic/HighendC++/` | 명품 C++ 교재 ch5~ch11 예제 및 연습문제 |
| `C++/C++basic/HighendC++/ch8/` | 상속 (예제 4개, 연습문제 5개) |
| `C++/C++basic/HighendC++/ch9/` | 가상 함수와 추상 클래스 (예제 7개, 연습문제 2개) |
| `C++/C++basic/HighendC++/ch10/` | 템플릿과 STL (예제 12개) |
| `C++/C++basic/HighendC++/ch11/` | 표준 템플릿 라이브러리 STL (예제 3개) |
| `C++/C++basic/forzan_cpp/` | 포르잔 C++ ch4~ch9 예제 및 실습 |
| `C++/PS/algorithm_for_PS/` | 실전 알고리즘 교재 예제·연습문제 (1장 알고리즘과 계산량, 2장 누적합, 3장 이진 탐색, 4장 동적 계획법, 5장 수학적 문제, 진행 중) |
| `C++/PS/contest/atcoder/abc/` | [AtCoder](https://atcoder.jp/) ABC 시리즈 문제 풀이 (대회별 하위 폴더) |
| `C++/PS/contest/atcoder/awc/` | [AtCoder](https://atcoder.jp/) AWC 시리즈 문제 풀이 (대회별 하위 폴더) |
| `C++/PS/contest/atcoder/TRACKER.md` | AtCoder 풀이 트래커 (문제·풀이 날짜·복습 필요 여부·메모) |
| `C++/PS/contest/codeforces/` | [Codeforces](https://codeforces.com/) 문제 풀이 |
| `C++/PS/contest/codeforces/TRACKER.md` | Codeforces 풀이 트래커 (문제·풀이 날짜·복습 필요 여부·메모) |
| `C++/PS/contest/codeforces/Div2/` | Div.2 라운드 문제 풀이 (대회별 하위 폴더) |
| `C++/PS/contest/codeforces/Div3/` | Div.3 라운드 문제 풀이 (대회별 하위 폴더) |
| `C++/PS/contest/codeforces/unknowned/` | 대회 미상 Codeforces 문제 풀이 |
| `C++/PS/justProblems/SPOJ/before 1000s/` | [SPOJ](https://www.spoj.com/) 1000번 이전 문제 풀이 |
| `C++/PS/justProblems/kattis/` | [Kattis](https://open.kattis.com/) 문제 풀이 |
| `testdata/` | expert_c/DSA 실습에서 참조하는 공용 테스트 데이터, 바이너리 분석 산출물(`expert_c_artifacts/`) |
| `clean_build.sh` | 하위 폴더의 컴파일 산출물(오브젝트/실행 파일)을 재귀적으로 정리하는 스크립트 |

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
g++ -std=c++20 -O2 -o solution solution.cpp

# 디버그 빌드 (VSCode Ctrl+Shift+B와 동일)
g++ -fdiagnostics-color=always -g solution.cpp -o solution.exe

# C 단일 파일 컴파일
gcc -o program program.c

# 실행
./solution.exe
```

---

## 문제풀이 현황

> 문제별 풀이 날짜, 복습 필요 여부, 메모 등 상세 기록은 [AtCoder 트래커](C++/PS/contest/atcoder/TRACKER.md) / [Codeforces 트래커](C++/PS/contest/codeforces/TRACKER.md) 참고.

### AtCoder

**ABC** (31개 대회, 94문제)

| 대회 | 풀이 문제 |
|------|-----------|
| ABC437 | A, B, C, D |
| ABC438 | A, B, C |
| ABC439 | A, B, C |
| ABC440 | A, B |
| ABC441 | A, B, C |
| ABC442 | A, B, C |
| ABC443 | A, B, C |
| ABC444 | A, B, C, D |
| ABC445 | A, B, C |
| ABC446 | A, B, C |
| ABC447 | A, B, C, D |
| ABC448 | A, B, C |
| ABC449 | A, B, C |
| ABC450 | A, B, C, D |
| ABC451 | A, B, C |
| ABC452 | A, B, C |
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
| ABC466 | A, B, C, D |
| ABC467 | A, B, C, D |
| ABC469 | A, B, C, D |

**AWC** (16개 대회, 31문제)

| 대회 | 풀이 문제 |
|------|-----------|
| AWC0061 | A, B |
| AWC0062 | A, B |
| AWC0063 | A, B |
| AWC0064 | A, B, C |
| AWC0068 | A, B |
| AWC0071 | A, B |
| AWC0079 | A |
| AWC0081 | A, B, C |
| AWC0094 | A, B |
| AWC0100 | A, B |
| AWC0103 | A, B |
| AWC0104 | A, B |
| AWC0108 | A, B |
| AWC0111 | A |
| AWC0112 | A |
| AWC0124 | A, B |

### Codeforces (6개 라운드 + 미상, 16문제)

| 대회 | 풀이 문제 |
|------|-----------|
| CF 1103 (Div.3) | A, B |
| CF 1106 (Div.2) | A |
| CF 1107 (Div.3) | A, B |
| CF 1109 (Div.3) | A, B |
| CF 1111 (Div.2) | A |
| 대회 미상(unknown) | 50A, 71A, 112A, 158A, 236A, 263A, 339A, 937A |

### SPOJ / Kattis

| 사이트 | 문제 | 비고 |
|--------|------|------|
| [SPOJ](https://www.spoj.com/) | 74 | 약수의 합 (에라토스테네스 체 응용) |
| [Kattis](https://open.kattis.com/) | 99 Problems, lv_able | 문자열/구현 문제 |

---

## 학습 목표

- [ ] AtCoder 레이팅 1000점
- [ ] Codeforces 레이팅 획득
- [ ] C++ STL 및 알고리즘 숙달
- [x] 자료구조 (연결리스트, 트리, 큐 등) 직접 구현
- [x] Expert C/C++ 스터디 시작
- [x] 정렬·검색·힙·해시테이블·문자열탐색·그래프(DFS/BFS, 위상정렬, 최소신장트리, 다익스트라)·분할정복·동적계획법 알고리즘 직접 구현
- [x] 윤성우 TCP-IP 프로그래밍 
- [ ] CLRS 알고리즘 재구현 (삽입 정렬부터 시작)
- [ ] 실전 알고리즘 스터디 (알고리즘과 계산량부터 시작)

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

**동적 계획법(Dynamic Programming)**

| 알고리즘 | 파일 | 설명 |
|----------|------|------|
| 피보나치 | `Algoruithm_paradigm/Dynamic_Programming/Fibonacci.c` | 테이블(메모이제이션)에 기록하며 O(n)에 피보나치 수 계산 |
| 최장 공통 부분 수열 (분할 정복) | `Algoruithm_paradigm/Dynamic_Programming/LCSDC.c` | 재귀적 분할 정복 방식으로 LCS 길이 계산 |
| 최장 공통 부분 수열 (동적 계획법) | `Algoruithm_paradigm/Dynamic_Programming/LCSDP.c` | 2차원 테이블 기반 상향식(bottom-up) LCS 계산 |

---

## CLRS 재구현

CLRS(Introduction to Algorithms) 교재 기반으로 재구현한 알고리즘입니다.

| 알고리즘 | 파일 | 설명 |
|----------|------|------|
| 삽입 정렬 | `CLRS/ch2/insertation_sort.c` | 배열을 앞에서부터 순회하며 정렬된 부분에 키 값을 삽입 |
