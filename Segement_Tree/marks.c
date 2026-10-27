#include <stdio.h>

int main() {
    int a, b, c, d, e;
    printf("Enter 5 subject marks: ");
    // Make sure your input numbers are separated by spaces or enters when typing
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    int total = a + b + c + d + e;
    
    // FIX: Changing 5 to 5.0 forces C to calculate accurate decimals
    float percentage = total / 5.0; 
    
    printf("Total marks obtained: %d \n", total);
    // Optional: Print the percentage to check accuracy
    printf("Percentage: %.2f%%\n", percentage); 
    
    if (percentage >= 90) {
        printf("A grade\n");
    }
    else if (percentage >= 80) {
        printf("B grade\n");
    }
    else if (percentage >= 70) {
        printf("C grade\n");
    }
    else {
        printf("Fail\n");
    }
    
    return 0;
}