
#include <stdio.h>

long long factorial(int n) {
    long long fact = 1;

    for (int i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}

void callByValue(int x) {
    x = x + 10;
    printf("Inside Call by Value: %d\n", x);
}

void callByReference(int *x) {
    *x = *x + 10;
    printf("inside call by refernce %d \n",*x);
}

int main() {
    int n, a = 10, b = 10;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 0 || n > 20) {
        printf("Enter a number between 0 and 20.\n");
        return 0;
    }

    long long f = factorial(n);

    printf("Factorial of %d is: %lld\n", n, f);

    printf("\nCall by Value:\n");
    printf("Before: %d\n", a);
    callByValue(a);
    printf("After: %d\n", a);

    printf("\nCall by Reference:\n");
    printf("Before: %d\n", b);
    callByReference(&b);
    printf("After: %d\n", b);

    return 0;
}