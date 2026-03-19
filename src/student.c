#include "student.h"
#include <stdio.h>
#include <string.h>

float calculateAverage(int grades[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return (float)sum / count;
}

void inputStudents(STUD students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Студент %d:\n", i + 1);
        printf("  Фамилия и инициалы: ");
        scanf(" %[^\n]", students[i].name);
        printf("  Группа (факультет, курс, номер группы): ");
        scanf(" %[^\n]", students[i].group);
        printf("  Введите 4 оценки через пробел: ");
        for (int j = 0; j < SES_COUNT; j++) {
            scanf("%d", &students[i].ses[j]);
        }
    }
}

void sortByName(STUD students[], int count) {
    STUD temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printExcellentStudents(STUD students[], int count) {
    struct {
        STUD student;
        float average;
        int originalIndex;
    } excellent[count], temp;
    
    int excellentCount = 0;
    
    for (int i = 0; i < count; i++) {
        float avg = calculateAverage(students[i].ses, SES_COUNT);
        if (avg > 4.2) {
            excellent[excellentCount].student = students[i];
            excellent[excellentCount].average = avg;
            excellent[excellentCount].originalIndex = i;
            excellentCount++;
        }
    }
    
    if (excellentCount == 0) {
        printf("\nНет студентов со средним баллом выше 4.2\n");
        return;
    }
    
    for (int i = 0; i < excellentCount - 1; i++) {
        for (int j = i + 1; j < excellentCount; j++) {
            if (excellent[i].average > excellent[j].average) {
                temp = excellent[i];
                excellent[i] = excellent[j];
                excellent[j] = temp;
            }
        }
    }
    
    printf("\nСтуденты со средним баллом > 4.2:\n");
    printf("--------------------------------------------------------\n");
    printf("№ в исх. списке | %-20s | %-15s | Ср. балл\n", "Фамилия", 
"Группа");
    printf("--------------------------------------------------------\n");
    
    for (int i = 0; i < excellentCount; i++) {
        printf("       %-2d        | %-20s | %-15s | %.2f\n",
               excellent[i].originalIndex + 1,
               excellent[i].student.name,
               excellent[i].student.group,
               excellent[i].average);
    }
    printf("--------------------------------------------------------\n");
}
