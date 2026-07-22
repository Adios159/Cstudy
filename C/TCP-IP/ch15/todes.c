#include <stdio.h>
#include <fcntl.h>
int main(void) {
    FILE* fp;
    int fd = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if(fd == -1) {
        fputs("FILE ERROR!", stdout);
        return -1;
    }

    printf("First file descripter: %d\n", fd);
    fp = fdopen(fd, "w");
    fputs("TCP/IP SOCKET PROGRAMMING\n", fp);
    printf("Second file descriptor: %d\n", fileno(fp));
    fclose(fp);
    return 0;
}