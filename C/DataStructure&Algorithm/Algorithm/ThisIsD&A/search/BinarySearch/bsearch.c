#include <stdio.h>
#include <stdlib.h>
#include "point.h"

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
    Point target;

    qsort((void*)DataSet, length, sizeof(Point), compare_point);
    target.id = 1780;
    target.point - 671.78;
    found = bsearch((void*)&target, (void*)DataSet, length, sizeof(Point), compare_point);
    if(found == NULL) {
        printf("not found!\n");
        return 0;
    }
    printf("found...\n");
    printf("Id: %d\nPoint: %f\n", found->id, found->point);

    return 0;

}