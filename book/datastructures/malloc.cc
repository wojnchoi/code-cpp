#include<iostream>
#include<malloc.h>
#include<cstdlib>

#define SIZE 10


int main()
{
    int *p;
    p = (int*)malloc(SIZE * sizeof(int));
    if(p==NULL)
        {fprintf(stderr,"failed to malloc\n");
        exit(1);}

    for(int i=0; i<SIZE;i++)
        p[i] = i;
    
    for(int i=0; i<SIZE;i++)
        std::cout<<p[i]<<" "<<std::endl;

    free(p);
    return 0;
}