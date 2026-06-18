#include <stdio.h>
#ifdef __INTELLISENSE__
typedef struct sample_t {
#else
typedef struct __attribute__((__packed__)) sample_t {
#endif
    char first;
    char second;
    char third;
    short fourth;
} sample_t;

// typedef struct __attribute__((__packed__)) sample_t {
//     char first;
//     char second;
//     char third;
//     short fourth;
// } sample_t;

void print_size(sample_t* var) {
    printf("size: %lu bytes\n", sizeof(*var));
}

void print_bytes(sample_t* var) {
    unsigned char* ptr = (unsigned char*)var;
    for(int i = 0; i < sizeof(*var); i++, ptr++) {
        printf("%d ", (unsigned int)*ptr);
    }
    printf("\n");
}

int main() {
    sample_t var;
    var.first = 'A';
    var.second = 'B';
    var.third = 'C';
    var.fourth = 456;

    print_size(&var);
    print_bytes(&var);

    return 0;
}