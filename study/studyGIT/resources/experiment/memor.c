#include<stdio.h>
#include<stdlib.h>
int main(){
    char *str;
    str = (char*)malloc(15);
    strcpy(str,"helloworld");
    printf("%s, %u\n",str,str);

    str = (char*) realloc(str, 25);
    strcat(str,".com");
    printf("%s,%u\n", str, str);

    return 0;
}