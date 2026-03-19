#ifndef STUDENT_H
#define STUDENT_H

#define STUDENTS_COUNT 10
#define SES_COUNT 4

typedef struct {
    char name[50];           
    char group[20];          
    int ses[SES_COUNT];      // успеваемость (4 оценки)
    float average;           
    int original_index;      // исходная позиция в списке
} STUD;

void inputStudents(STUD students[], int count);
void sortByName(STUD students[], int count);
void printExcellentStudents(STUD students[], int count);
void sortByAverage(STUD excellent[], int excellentCount);
float calculateAverage(int grades[], int count);

#endif
