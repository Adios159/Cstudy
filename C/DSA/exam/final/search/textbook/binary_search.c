int search_binary(int list[], int key, int low, int high)
{
    int middle;
    while (low <= high) {
        middle = (low + high) / 2;
        if (key == list[middle]) return middle;
        else if (key > list[middle]) low = middle + 1;
        else high = middle - 1;
    }
    return -1;
}

int search_binary_rec(int list[], int key, int low, int high)
{
    int middle;
    if (low <= high) {
        middle = (low + high) / 2;
        if (key == list[middle]) return middle;
        else if (key < list[middle])
            return search_binary_rec(list, key, low, middle - 1);
        else
            return search_binary_rec(list, key, middle + 1, high);
    }
    return -1;
}