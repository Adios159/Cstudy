#include <stdio.h>

int main(int argc, char** argv) {
#if __STDC_VERSION__ >= 20170L
    printf("Hello world from C18!\n");
#endif
    return 0;
}