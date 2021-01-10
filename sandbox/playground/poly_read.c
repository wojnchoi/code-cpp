#include<stdio.h>
#include<stdlib.h>

#define MAX_NUM 101

typedef struct
{
    int degree;
    float coef[MAX_NUM];
} polynomial1;

typedef struct 
{
    float coef;
    int degree;
} polynomial2;

polynomial1 a = {3, {1,2,0,4}};
polynomial2 b[MAX_NUM] = {{1,3},{2,2},{0,1},{4,0}};

void poly_read(polynomial1 a, polynomial2 b[])
{
    for(int i = a.degree; i >0; i--)
        printf("%3.1fx^%d + ",a.coef[a.degree-i],i);
    printf("%3.1f \n",a.coef[a.degree]);

    for(int i = 0; i < 3; i++)
    {
        printf("%3.1fx^%d + ", b[i].coef, b[i].degree);
    }
    printf("%3.1fx^%d\n",b[3].coef, b[3].degree);
        
}

int main()
{
    poly_read(a, b);
    return 0;
}