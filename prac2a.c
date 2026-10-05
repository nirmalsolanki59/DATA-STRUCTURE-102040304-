/*
    Data Structures Practical 2(A) Aim: Write a program to print array elements in reverse order using pointers.
*/

#include <stdio.h>

int main()
{
    int a[100], n, i;
    int *p;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    p = &a[n - 1];

    printf("Array in reverse order:\n");
    for(i = n - 1; i >= 0; i--)
    {
        printf("%d ", *p);
        p--;
    }

    return 0;
}