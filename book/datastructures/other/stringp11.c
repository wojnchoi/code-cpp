#include<stdio.h>
#include<ctype.h>
#define STACK_SIZE 100
#define SIZE 20
typedef char element;
typedef struct {
    element data[STACK_SIZE];
    int top;
} STACK;

void STACK_INIT(STACK *s) {
    s->top = -1;
}
int is_full(STACK *s) {
    return (s->top == (STACK_SIZE-1));
}
int is_empty(STACK *s) {
    return (s->top == -1);
}
void push(STACK *s, element item) {
    s->data[++(s->top)] = item;
}
element pop(STACK *s) {
    return s->data[(s->top)--];
}
element peek(STACK *s) {
    return s->data[s->top];
}

int main() {

    char str[SIZE] = "";
    int count = 0;
    STACK s;
    STACK_INIT(&s);
    printf("enter a string : ");
    scanf("%s", str);
    for(int i=0;i<SIZE;i++) {
        char chr = tolower(str[i]);
        if(is_empty(&s) || chr == peek(&s))  {
            count++;
            push(&s, chr);
        }
        else if(chr != peek(&s)) {
            printf("%d%c", count, peek(&s));
            count = 0;
            while(!is_empty(&s))
                pop(&s);
            i--;
        } 
    }
    printf("\n");
    return 0;
}