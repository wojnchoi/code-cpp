#include<stdio.h>

static unsigned hexval(char c) //unsigned default is unsigned int
{
    if(c>='0' && c<='9')
        return c - '0';
    if(c>='a' && c<='f')
        return c - 'a' + 10;
    if(c>='A' && c <='F')
        return c - 'A' + 10;
    return ~0;
}
int main()
{
    char ch;
    scanf("%c", &ch);
    int value = hexval(ch);
    printf("%u\n", value);
    printf("%d\n", ~0);
    return 0;
}