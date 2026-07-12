#include <stdio.h>
#include <stdlib.h>
#include "point.h"

Point* binary_search(Point data[], int size, double target) {
    int left, right, mid;
    left = 0;
    right = size - 1;
    while(left <= right) {
        mid = (left + right) / 2;
        if(target == data[mid].point)
            return &(data[mid]);
        else if(target > data[mid].point)
            left = mid + 1;
        else    
            right = mid - 1;
    }
    return NULL;
}

int compare_point(const void* _elem1, const void* _elem2) {
    Point* elem1 = (Point*)_elem1;
    Point* elem2 = (Point*)_elem2;

    if(elem1->point > elem2->point) {
        return 1;
    }
    else if(elem1->point < elem2->point) {
        return -1;
    }
    else
        return 0;
}

int main(void) {
    int length = sizeof(DataSet) / sizeof(DataSet[0]);
    Point* found = NULL;

    qsort((void*)DataSet, length, sizeof(Point), compare_point);
    found = binary_search(DataSet, length, 671.78);
    if(found == NULL) {
        printf("not found!\n");
        return 0;
    }
    printf("found...\n");
    printf("Id: %d\nPoint: %f\n", found->id, found->point);
    
    return 0; 
}