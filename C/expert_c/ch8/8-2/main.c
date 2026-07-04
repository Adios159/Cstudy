#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "student.h"

int main(void) {
    struct student* student = student_new();
    student_ctor(student, "John", "Doe", 1987, "TQ4885", 134);

    char buffer[32];
    struct person* person_ptr = (struct person*)student;

    person_get_first_name(person_ptr, buffer);
    printf("first name: %s\n", buffer);
    person_get_last_name(person_ptr, buffer);
    printf("last name: %s\n", buffer);
    student_get_student_number((struct student*)person_ptr, buffer);
    printf("student number: %s\n", buffer);

    printf("birth year: %d\n", person_get_birth_year(person_ptr));
    printf("passed credit: %d\n", student_get_passed_credit(student));


    student_dtor(student);
    free(student);
}