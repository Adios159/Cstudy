#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    void *ptr = malloc(1024);
    printf("Address: %p\n", ptr);
    fflush(stdout);
    while(1) {
        sleep(1);     
    };
    return 0;
}

