#include "BruteForce.h"

int BruteForce(char* text, int size, int start, char* pattern, int patternSize) {
    int i = 0, j = 0;
    for(i = start; i < size - patternSize; i++) {
        for(j = 0; j < patternSize; j++) {
            if(text[i + j] != pattern[j]) 
                break;
        }
        if(j >= patternSize)
            return i;
    }
    return -1;
}