#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("\nRight Triangle:\n");
    for (int i = 0; i < n; i++) {
        // FIX: Changed j < i to j <= i so the first row prints 1 star
        for (int j = 0; j <= i; j++) { 
            printf("*");
        }
        printf("\n");
    }

    printf("\nReverse Right Triangle:\n");
    for (int i = 0; i < n; i++) {
        // This loop works perfectly for the inverted pattern
        for (int j = i; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}