#include<iostream>
#include<stdlib.h>
#include<cstring>
#define SIZE 20

typedef struct
{
    int a;
    char b[SIZE];
}gujoche;

int main()
{
    gujoche *result = (gujoche*)malloc(sizeof(gujoche));
    result->a = 100;
    strcpy(result->b,"just testing");

    std::cout<<result->a<<" "<<result->b<<std::endl;
    free(result);
    return 0;
}