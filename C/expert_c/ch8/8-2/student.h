#pragma once

struct student;
struct student* student_new();
void student_ctor(struct student*,
                  const char*,
                  const char*,
                  unsigned int,
                  const char*,
                  unsigned int);
void student_dtor(struct student*);
void student_get_student_number(struct student*, char*);
unsigned int student_get_passed_credit(struct student*);