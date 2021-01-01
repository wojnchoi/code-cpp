#include<stdio.h>

int main()
{
    unsigned int num1 = 7; // 0000 0111
    unsigned int num2 = 4; // 0000 0100

    printf("%d\n", num1 & num2); 
    printf("%d\n", num1 | num2);
    printf("%d\n", num1 ^ num2);
    printf("%d\n", ~num1);
    return 0;
}