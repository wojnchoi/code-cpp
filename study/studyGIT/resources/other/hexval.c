#include<stdio.h>

static unsigned hexval(char c)
{
	if(c >= '0' && c <= '9')
		return c - '0';
	if(c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	if(c >= 'A' && c <= 'F')
		return c - 'A' + 10;

	return ~0;
}
int main(int argc, char* argv[])
{
	char* hex = argv[1];
		unsigned int val = (hexval(hex[0]) << 4 | hexval(hex[1]));
		printf("%u\n", val);
	return 0;
}

