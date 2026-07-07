#include "common.h"

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}
