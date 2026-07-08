#pragma once

int karp_rabin(char* text, int size, int start, char* pattern, int patternSize);
int hash(char* string, int size);
int rehash(char* string, int start, int size, int hashPrev, int coefficient);