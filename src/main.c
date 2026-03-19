#include <stdio.h>
#include "student.h"

int main() {
    STUD students[STUDENTS_COUNT];
    
    printf("=== Программа учета успеваемости студентов ===\n");
    printf("Введите данные о %d студентах:\n\n", STUDENTS_COUNT);
    
    inputStudents(students, STUDENTS_COUNT);
    
    sortByName(students, STUDENTS_COUNT);
    
    printExcellentStudents(students, STUDENTS_COUNT);
    
    return 0;
}
