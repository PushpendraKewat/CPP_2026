#include <stdio.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    struct Student s[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].rollNo);

        printf("Name: ");
        scanf(" %49[^\n]", s[i].name);

        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\n--- Student Information ---\n");

    for (i = 0; i < 5; i++) {
        printf("\nRoll Number: %d\n", s[i].rollNo);
        printf("Name: %s\n", s[i].name);
        printf("Marks: %.2f\n", s[i].marks);
    }

    return 0;
}