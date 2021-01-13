#include<stdio.h>
#include<ctype.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;
}STACK;
void init(STACK *s) {
    s->top = -1;
}
int is_full(STACK *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
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
    if(!is_empty)
        return s->data[s->top];
}

int main()
{
    STACK s;
    init(&s);
    char arr[MAX_STACK_SIZE];
    printf("enter a string: ");
    scanf("%s", arr);
    int i = 0, result = 1;
    while(arr[i] != '\0') {
            push(&s,tolower(arr[i]));
        i++;
    }
    i = 0;
    while(arr[i] != '\0') {
			if (pop(&s) != tolower(arr[i])) {
				result = 0;
				break;
			}
        i++;
    }
    if(result)
    printf("palindrom\n");
    else 
    printf("not palindrome\n");
    return 0;
}