#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(void) {
    struct student* student = student_new();
    student_ctor(student, "John", "Doe", 1987, "TQ4885", 134);

    char buffer[32];

    student_get_first_name(student, buffer);
    printf("first name: %s\n", buffer);
    student_get_last_name(student, buffer);
    printf("last name: %s\n", buffer);
    student_get_student_number((struct student*)student, buffer);
    printf("student number: %s\n", buffer);

    printf("birth year: %d\n", student_get_birth_year(student));
    printf("passed credit: %d\n", student_get_passed_credit(student));


    student_dtor(student);
    free(student);
}