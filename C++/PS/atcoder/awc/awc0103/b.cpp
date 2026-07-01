#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    long long sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++){
        long long a, b;
        scanf("%lld %lld", &a, &b);
        sumA += a;
        sumB += b;
    }
    printf("%lld\n", min(sumA, sumB));
    return 0;
}