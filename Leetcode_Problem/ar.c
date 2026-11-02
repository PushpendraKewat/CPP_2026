
#include <stdio.h>

int main()
{
    int n, i;
    int sum = 0;
    int *ptr;

    printf("Enter array size : ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid array size!");
        return 1;
    }

    int a[n];

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    ptr = a;

    for (i = 0; i < n; i++)
    {
        sum += *(ptr + i);
    }

    printf("Sum of array elements = %d\n", sum);

    return 0;
}
