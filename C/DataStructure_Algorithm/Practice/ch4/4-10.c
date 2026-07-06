#include <stdio.h>

int calc_log_2(int num, int cnt) {
    if(num == 1 || num == 0) {
        return cnt;
    }
    return calc_log_2(num / 2, ++cnt);
}

int main(void) {
    int num  = 32;
    int ans = calc_log_2(num, 0);
    printf("%d\n", ans);
    return 0;
}