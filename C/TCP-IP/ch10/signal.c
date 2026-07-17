#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeout(int sig) {
    if(sig == SIGALRM) {
        puts("Time out!!");
    }
    alarm(2);
}

void key_control(int sig) {
    if(sig == SIGINT) {
        puts("\nCTRL + C pressed!");
    }
}

int main(void) {
    int i;
    signal(SIGALRM, timeout);
    signal(SIGINT, key_control);
    alarm(2);

    for(i = 0; i < 3; i++) {
        puts("wait...");
        sleep(100);
    }
    return 0;
}