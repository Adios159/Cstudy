#include <stdio.h>

int* get_integer() {
    int var = 10;
    return &var;
}  

int main(void) {
    int* ptr = get_integer();
    *ptr = 5;
    return 0;
}
