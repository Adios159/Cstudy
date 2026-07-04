#include <string.h>
#include <stdlib.h>
#include "person.h"
#include "person_s.h"

void person_ctor(struct person* person, 
                const char* first_name,
                 const char* last_name,
                  unsigned int birth_year) {
    strcpy(person->first_name, first_name);
    strcpy(person->last_name, last_name);
    person->birth_year = birth_year;
} //(firstname, last name, birth year)

void person_dtor(struct person* person) {

}

void person_get_first_name(struct person* person, char* buffer) {
    strcpy(buffer, person->first_name);
}

void person_get_last_name(struct person* person, char* buffer) {
    strcpy(buffer, person->last_name);
}

unsigned int person_get_birth_year(struct person* person) {
    return person->birth_year;
}
