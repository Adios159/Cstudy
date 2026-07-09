#include "BruteForce.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFFER 512

int main(int argc, char** argv) {
    char text[MAX_BUFFER];
    char pattern[MAX_BUFFER];
    int patternSize = 0;
    int line = 0;
    printf("what kind of word do you want to find> ");
    scanf("%s", pattern);
    patternSize = strlen(pattern);

    FILE* fp = fopen("kjv.txt", "r");
    if(fp == NULL) {
        printf("Invailed FILE!");
        exit(1);
    }

    while(fgets(text, MAX_BUFFER, fp) != NULL) {
        int position = BruteForce(text, strlen(text), 0, pattern, patternSize);
        line++;
        if(position >= 0) {
            printf("line: %d, column: %d : %s", line, position + 1, text);
        }
    }
    fclose(fp);
    return 0;
}