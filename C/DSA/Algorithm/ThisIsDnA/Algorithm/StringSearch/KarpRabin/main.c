#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "KarpRabin.h"

int main(int argc, char** argv) {
    FILE* fp = fopen("kjv.txt", "r");
    if(fp == NULL) {
        printf("No FILE!");
        exit(1);
    }

    char text[512];
    char* pattern;
    int patternSize = 0;
    int line = 0;

    pattern = argv[1];
    patternSize = strlen(pattern);

    while(fgets(text, 512, fp) != NULL) {
        int position = karp_rabin(text, strlen(text), 0, pattern, patternSize);
        line++;
        if(position >= 0) {
            printf("line: %d, column: %d : %s", line, position + 1, text);
        }
    }
    fclose(fp);
    return 0;
}