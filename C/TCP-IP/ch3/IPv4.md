# IPv4주소의 표현
## 주소 정보의 표현
IP주소에는 다음과 같은 정보가 포함되어야함
 - 주소체계
 - IP주소
 - 포트번호

## 소켓주소 구조체
```C
struct sockaddr_in {
    sa_family_t sin_family; //주소체계
    uint16_t sin_port; //16비트 포트번호
    struct in_addr sin_addr; //32비트 IP주소
    chaqr sin_zero[8]; //사용하지 않음
};
```
## 구조체 멤버 변수 분석
### sin_family
주소에 적용하게 될 주소체계를 결정
| 주소체계 | 의미 |
| --- | --- |
| AF_INET | IPv4 인터넷 프로토콜에 적용하는 주소체계 |
| AF_INET6 | IPv6 인터넷 프로토콜에 적용하는 주소체계 |
| AF_LOCAL | 로컬 유닉스 통신을 위한 주소체계 |
### sin_port
- 16비트 포트번호를 저장
-네트워크 바이트 순서로 저장해야함
### sin_addr
- 32비트 IP주소 정보를 저장
- sockaddr 구조체와의 크기를 일치시키기 위해 임의로 넣은 멤버 변수
- 반드시 0으로 채워야