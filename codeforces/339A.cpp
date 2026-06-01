#include <iostream>
#include <string>
#include <algorithm> //정렬 알고리즘 추가
using namespace std;

int main() {
    int num[101], idx = 0;
    string formula;

    cin >> formula;
    for(int i = 0; i < formula.length(); i++) {
        if(formula[i] != '+') {
            num[idx] = formula[i] - '0';  //실제 숫자로 변환
            idx++;
        }
    }
    sort(num, num + idx);  //배열 정렬

    for(int j = 0; j < idx; j++) {
    if(j == idx - 1)
        cout << num[j];       //마지막 인덱스 출력 보정
    else
        cout << num[j] << '+'; 
    }   

    return 0;
}