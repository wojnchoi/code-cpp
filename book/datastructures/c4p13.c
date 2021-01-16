#include<stdio.h>

#define SIZE 100

typedef int element;
typedef struct
{
    element data[SIZE];
    int top;
}STACK;

void init_stack(STACK *s) {
    s->top = -1;
}
int is_full(STACK *s) {
    return (s->top == SIZE - 1);
}
int is_empty(STACK *s) {
    return (s->top == -1);
}
void push(STACK *s, element item) {
    if(!is_full(s)) {
        s->data[++(s->top)] = item;
    }
}
element pop(STACK *s) {
    if(!is_empty(s)) {
        return s->data[(s->top)--];
    }
}
element peek(STACK *s) {
    if(!is_empty(s)) {
        return s->data[s->top];
    }
}

int main()
{
    STACK s;
    STACK a;
    char input[SIZE], i=0;
    init_stack(&a);
    init_stack(&s);
    
    printf("enter integer: ");
    scanf("%s", input);
    while(input[i] != '\0') {
        if(input[i] != input[i+1]) {
            push(&s,input[i] - '0');
        }
        i++;
    }
    printf("output: ");
    while(!is_empty(&s)) {
        push(&a,pop(&s));
    }
    while(!is_empty(&a))
        printf("%d", pop(&a));
    printf("\n");
    return 0;
}
