#include <stdio.h>

typedef struct {
    char first_name[32];
    char last_name[32];
    unsigned int birth_year;
} Person;

typedef struct student
{
    Person person;
    char student_number[16];
    unsigned int passed_credits;
} student;

int main() {
    student s;
    student* s_ptr = &s;
    Person* p_ptr = (Person*)&s;
    printf("Student pointer poiint at: %p\n", (void*)s_ptr);
    printf("Person pointer point at: %p\n", (void*)p_ptr);
    return 0;
}
