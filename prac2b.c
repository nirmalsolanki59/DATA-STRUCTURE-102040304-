/*
    Data Structures Practical 2(B) Aim: Demonstrate the concept of Call by Value and Call by Reference.
*/

#include <stdio.h>

void callByValue(int x)
{
    x = x + 10;
    printf("Inside Call by Value: %d\n", x);
}

void callByReference(int *x)
{
    *x = *x + 10;
    printf("Inside Call by Reference: %d\n", *x);
}

int main()
{
    int a = 20;
    int b = 20;

    printf("Before Call by Value: %d\n", a);
    callByValue(a);
    printf("After Call by Value: %d\n\n", a);

    printf("Before Call by Reference: %d\n", b);
    callByReference(&b);
    printf("After Call by Reference: %d\n", b);

    return 0;
}
