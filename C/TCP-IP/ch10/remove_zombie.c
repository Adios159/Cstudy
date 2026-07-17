#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void read_chileproc(int sig) {
    int status;
    pid_t id = waitpid(-1, &status, WNOHANG);
    if(WIFEXITED(status)) {
        printf("Removed proc id: %d\n", id);
        printf("Chile send: %d\n", WEXITSTATUS(status));
    }
}

int main(void) {
    pid_t pid;
    struct sigaction act;
    act.sa_handler = read_chileproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGCHLD, &act, 0);
    
    pid = fork();
    if(pid== 0) {
        puts("Hi i'm child process");
        sleep(10);
        return 12;
    }
    else {
        printf("Chile proc id: %d\n", pid);
        pid = fork();
        if(pid == 0) {
            puts("hi i'm child process");
            sleep(10);
            exit(24);
        }
        else {
            int i;
            printf("Chile proc id: %d\n", pid);
            for(i = 0; i < 5; i++) {
                puts("Wait...");
                sleep(5);
            }
        }
    }
    return 0;
}