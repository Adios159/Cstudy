#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int key;
typedef int value;
typedef struct Node {
    key Key;
    value Value;
} Node;

typedef struct HashTable {
    int tableSize;
    Node* table;
} HashTable;

HashTable* create(int tableSize);
void set(HashTable* ht, key Key, value Value);
value get(HashTable* ht, key Key);
void destroy(HashTable* ht);
int hash(key Key, int tableSize);