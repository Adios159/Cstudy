#include <string.h>
#include <stdlib.h>

typedef struct person {
    char first_name[32];
    char last_name[32];
    unsigned int birth_year;
} person;

person* person_new() {
    return (person*)malloc(sizeof(person));
}

void person_ctor(person* person, 
                const char* first_name,
                 const char* last_name,
                  unsigned int birth_year) {
    strcpy(person->first_name, first_name);
    strcpy(person->last_name, last_name);
    person->birth_year = birth_year;
} //(firstname, last name, birth year)

void person_dtor(person* person) {

}

void person_get_first_name(person* person, char* buffer) {
    strcpy(buffer, person->first_name);
}

void person_get_last_name(person* person, char* buffer) {
    strcpy(buffer, person->last_name);
}

unsigned int person_get_birth_year(person* person) {
    return person->birth_year;
}
