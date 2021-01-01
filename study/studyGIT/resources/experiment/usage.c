#include<stdio.h>
#include<stdlib.h>
int main()
{
    usage("failed to program");
    return 0;
}

void usage(const char* cpp)
{
    (void) fprintf(stderr,*cpp++);
    for(;*cpp;cpp++)
        (void)fprintf(stderr,*cpp);
    exit(1);
}