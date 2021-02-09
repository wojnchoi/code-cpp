#include<stdio.h>

int getBit(int num, int i) {
    return (num & (1<<i)) != 0;
}
int main()
{
    unsigned int num1 = 7; // 0000 0111
    unsigned int num2 = 4; // 0000 0100

    printf("%d\n", num1 & num2); 
    printf("%d\n", num1 | num2);
    printf("%d\n", num1 ^ num2);
    printf("%d\n", ~num1);

    printf("%d\n",getBit(9,3));
    return 0;
}