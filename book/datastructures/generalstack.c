#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s)
{
    s->top = -1;
}

int is_empty(StackType *s)
{
    return (s->top == -1);
}

int is_full(StackType *s)
{
    return (s->top == MAX_STACK_SIZE -1);
}

void push(StackType *s, element item)
{
    if(is_full(s)) {
        fprintf(stderr,"full");
        return;
    } else
    {
        s->data[++(s->top)] = item;
    }
}

element pop(StackType *s)
{
    if(is_empty(s)) {
        fprintf(stderr,"empty\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s)
{
    if(is_empty(s)) {
        fprintf(stderr,"empty\n");
        exit(1);
    }
    else return s->data[s->top];
}

int main()
{
    StackType s;
    StackType b;
    init_stack(&s);
    init_stack(&b);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&b, pop(&s));
    push(&b, pop(&s));
    push(&b, pop(&s));
    printf("%d\n", pop(&b));
    printf("%d\n", pop(&b));
    printf("%d\n", pop(&b));
    return 0;
}