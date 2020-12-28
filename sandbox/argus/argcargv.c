#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    int i, sum = 0;
    printf("argc is %d\n", argc);
    if(argc > 1){
        for(i=0;i<argc;i++)
        {
            printf("argv[%d] = %s\n", i, argv[i]);
            sum += atoi(argv[i]);
        }
        printf("sum is %d\n", sum);
    } else {
        printf("not enough information\n");
    }
    return 0;
}

/*
if I start this program like
"./argc"

int argc will be 1 because it has 1 thing

if I start this program like
"./argc hello world"

int argc will be 3 because it has 3 things.

"./argc hello" => argc is 2!
*/