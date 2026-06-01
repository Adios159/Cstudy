#include <stdio.h>
#include <string.h>

#define CMD(NAME) \
    char NAME ## _cmd[256] = ""; \
    strcpy(NAME ## _cmd, #NAME);

int main(int args, char** argv) {
    CMD(copy)
    CMD(paste)
    CMD(cut)

    char cmd[256];
    scanf("%s", cmd);

    if (strcmp(cmd, copy_cmd) == 0) {
        printf("copy 실행\n");
    } 
    else if (strcmp(cmd, paste_cmd) == 0) {
        printf("paste 실행\n");
    } 
    else if (strcmp(cmd, cut_cmd) == 0) {
        printf("cut 실행\n");
    }

    return 0;
}