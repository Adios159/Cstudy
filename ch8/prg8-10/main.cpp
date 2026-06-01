#include "student.h"

int main() {
    Student students[5];

    students[0] = Student("George", 82);
    students[1] = Student("John", 71);
    students[2] = Student("Lucy", 91);
    students[3] = Student("Mary", 58);
    students[4] = Student("Kim", 65);
    for(int i = 0; i < 5; i++) {
        students[i].print();
    }
    return 0;
}