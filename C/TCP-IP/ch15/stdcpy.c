#include <stdio.h>
#define BUF_SIZE 3

int main(void) {
    FILE* fp1 = fopen("news.txt", "r");
    FILE* fp2 = fopen("cpy.txt", "w");
    char buf[BUF_SIZE];

    while(fgets(buf, BUF_SIZE, fp1) != NULL) {
        fputs(buf, fp2);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}