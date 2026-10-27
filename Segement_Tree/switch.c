#include <stdio.h>

int main() {
    int choice;
    float a, b;

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    switch (choice) {
        case 1:
            printf("Addition = %.2f\n", a + b);
            break;

        case 2:
            printf("Subtraction = %.2f\n", a - b);
            break;

        case 3:
            printf("Multiplication = %.2f\n", a * b);
            break;

        case 4:
            if (b != 0)
                printf("Division = %.2f\n", a / b);
            else
                printf("Division by zero is not allowed.\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}