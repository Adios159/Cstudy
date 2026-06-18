#include <stdio.h>

int main(int argc, char** argv) {
    int var = 1;

    int* iPtr = NULL; 
    iPtr = &var;

    char* cPtr = NULL;
    cPtr = (char*)&var;

    printf("Before arithmetic: iPtr: %u, cPtr: %u\n", (unsigned int)iPtr, (unsigned int)cPtr);

    iPtr++;
    cPtr++;

    printf("After arithmetic: iPtr: %u, cPtr: %u\n", (unsigned int)iPtr, (unsigned int)cPtr);

    return 0;
}