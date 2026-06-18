#include <stdio.h>

void func(int a) {
    a = 5;
}

int main(int argc, char** argv) {
    int a = 9;
    printf("%d\n", a);
    func(a);
    printf("%d", a);
    return 0;
}