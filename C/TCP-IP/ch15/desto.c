#include <stdio.h>
#include <fcntl.h>

int main(void) {
    FILE *fp;
    int fd = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if(fd == -1) {
        fputs("FILE ERROR!", stdout);
        return -1;
    }
    fp = fdopen(fd, "w");
    fputs("Network C programming\n", fp);
    fclose(fp);
    return 0;
}