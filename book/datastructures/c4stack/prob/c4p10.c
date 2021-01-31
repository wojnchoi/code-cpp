#include<stdio.h>

#define MAX_SIZE 100
#define SIZE 10
typedef struct Stacktype {
	int stack[MAX_SIZE];
	int top;
}Stacktype;

void init_stack(Stacktype* s) {
	s->top = -1;
}

void push(Stacktype* s, int item) {
	s->stack[++(s->top)] = item;
	return;
}

int is_empty(Stacktype* s) {
	return s->top == -1;
}

int pop(Stacktype* s) {
	int t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

int main(void) {
    
    char arr[SIZE];
    int count = 0;
    Stacktype s;
    init_stack(&s);
    printf("string : ");
    scanf("%s", arr);
    for(int i=0; i<SIZE;i++) {
        if(arr[i] == '(') {
            push(&s, ++count);
            printf("%d ", count);
        } else if(arr[i] == ')')
            printf("%d ", pop(&s));
         else {
            printf("\n");
            return 0;
        }
    }
	return 0;
}