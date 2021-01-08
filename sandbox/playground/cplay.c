#include<stdio.h>

void unknown()
{
	int ch;
	if((ch=getchar()) != '\n')
		unknown();
	putchar(ch);
}
int main()
{
	unknown();
	return 0;
}
