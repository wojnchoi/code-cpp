#include<stdio.h>
#include<string.h>
int main()
{
	const char str[] = "c language is the best!";
	const char ch = 'i';
	char* ret;
	
	ret=memchr(str,ch,strlen(str));
	printf("String after \"%c\" is \"%s\"\n", ch, ret);
	
	return 0;
}
