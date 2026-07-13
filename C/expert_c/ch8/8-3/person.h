#pragma once

struct person;
struct person* person_new();

void person_ctor(struct person*, const char*, const char*, unsigned int); //(firstname, last name, birth year)
void person_dtor(struct person*);
void person_get_first_name(struct person*, char*);
void person_get_last_name(struct person*, char*);
unsigned int person_get_birth_year(struct person*);