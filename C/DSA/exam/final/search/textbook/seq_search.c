#include <stdio.h>
#include <stdlib.h>

int seq_search(int list[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (list[i] == key) return i;
    return -1;
}

int seq_search_sentinel(int list[], int n, int key)
{
    int i = 0;
    list[n] = key;
    while (list[i] != key)
        i++;
    return (i == n) ? -1 : i;
}

int seq_search_sorted(int list[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++) {
        if (list[i] == key) return i;
        if (list[i] > key) return -1;
    }
    return -1;
}