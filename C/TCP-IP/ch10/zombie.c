#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    __pid_t pid = fork();

    if(pid == 0) {
        puts("Hi, I am chile process");
    }
    else {
        printf("Child Proc: %d\n", pid);
        sleep(30);
    }

    if(pid == 0) {
        puts("End child process");
    }
    else {
        puts("End parend process");
    }
    return 0;
}