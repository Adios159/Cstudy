# DNS
## DNS의 정의
- 어떤 서버에 접속을 할 떄에는 각 서버의 IP주소를 입력해야 한다.
- 그러나 IP주소는 기억하기 쉽지 않기때문에 표현하기 쉬운 형태의 주소로 대신하기도 한다
- 이를 도메인 주소라고 하고 도메인 주소를 IP주소로 변환하는 서버를 DNS서버라고 한다
- 모든 컴퓨터에는 디폴트 DNS서버가 있는데 이를 통해 메인 이름에 대한 IP주소를 얻는다
- 내 컴퓨터의 디폴트 서버가 모든 도메인의 IP주소를 아는것은 아니므로 모르는것은 다른 DNS 서버에게 묻는다
## 도메인을 쓰는 이유
- 프로그램을 사용하는 사용자에게 편리한 실행방법을 제시하는건 당연하다
- 그러므로 사용자가 IP주소를 직접 입력하게 하면 안됨
- 직접 IP주소와 포트번호를 하드코딩 하는건 IP주소거 변경될 확률이 높기 떄문에 불편함
- 그렇기 때문에 상대적으로 변경될 확률이 적은 도메인 주소를 이용함
## DNS서버 관련 함수
```C
struct hostnet {
    char* h_name;  //official name
    char** h_aliases   //alies list
    int h_addrtype  //host address type
    int h_length  //address length
    char** h_addr_list  //address list
}```
```C
struct hostnet* gethostbyname(const char* hostname);
```