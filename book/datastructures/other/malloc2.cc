#include<iostream>
#include<string.h>
#include<stdlib.h>

typedef struct studentTag {
    char name[10];
    int age;
    double gpa;
}student;


int main()
{
    student *s;
    s = (student*)malloc(sizeof(student));

    if(s == NULL) {
        fprintf(stderr,"failed to malloc\n");
        exit(1);
    }

    strcpy(s->name, "park");
    s->age = 20;

    std::cout<<s->name<<std::endl;
    std::cout<<s->age<<std::endl;
    free(s);
    return 0;
}