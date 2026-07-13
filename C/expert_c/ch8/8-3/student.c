#include <stdlib.h>
#include <string.h>
#include "person.h"

typedef struct student {
    char* student_number;
    unsigned int passed_credit;
    struct person* Person;
} student;

struct student* student_new() {
    return (student*)malloc(sizeof(student));
}

void student_ctor(student* student,
                  const char* first_name,
                  const char* last_name,
                  unsigned int birth_year,
                  const char* student_number,
                  unsigned int passed_credit) {
    student->Person = person_new();
    person_ctor((struct person*)student, first_name, last_name, birth_year);
    student->student_number = (char*)malloc(16 * sizeof(char));
    strcpy(student->student_number, student_number);
    student->passed_credit = passed_credit;
}

void student_dtor(struct student* student) {
    free(student->student_number);
    person_dtor((struct person*)student);
    free(student->Person);
}

void student_get_first_name(student* student, char* buffer) {
    person_get_first_name(student->Person, buffer);
}

void student_get_last_name(student*student, char* buffer) {
    person_get_last_name(student->Person, buffer);
}

unsigned int student_get_birth_year(student* student) {
    return person_get_birth_year(student->Person);
}

void student_get_student_number(struct student* student, char* buffer) {
    strcpy(buffer, student->student_number);
}

unsigned int student_get_passed_credit(struct student* student) {
    return student->passed_credit;
}