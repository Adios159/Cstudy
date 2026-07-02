#include "BasicHash.h"

HashTable* create(int tableSize) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (Node*)malloc(sizeof(Node) * tableSize);
    ht->tableSize = tableSize;

    return ht;
}

void set(HashTable* ht, key Key, value Value) {
    int adress = hash(Key, ht->tableSize);
    ht->table[adress].Key = Key;
    ht->table[adress].Value = Value;
}

value get(HashTable* ht, key Key) {
    int adress = hash(Key, ht->tableSize);
    return ht->table[adress].Value;
}

void destroy(HashTable* ht) {
    free(ht->table);
    free(ht);
}

int hash(key Key, int tableSize) {
    return Key % tableSize;
}