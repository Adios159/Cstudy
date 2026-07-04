#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "person_s.h"

typedef struct student {
    person* Person;
    char* student_number;
    unsigned int passed_credit;
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
    person_ctor((struct person*)student, first_name, last_name, birth_year);
    strcpy(student->student_number, student_number);
    student->passed_credit = passed_credit;
}

void student_dtor(struct student* student) {
    free(student->student_number);
    person_dtor((struct person*)student);
}

void student_get_student_number(struct student* student, char* buffer) {
    strcpy(buffer, student->student_number);
}

unsigned int student_get_passed_credit(struct student* student) {
    return student->passed_credit;
}