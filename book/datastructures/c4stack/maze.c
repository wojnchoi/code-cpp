#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAZE_SIZE 6

#define MAX_STACK_SIZE 100
typedef struct
{   short r;
    short c;
} element;

typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s) {
    s->top = -1;
}
int is_empty(StackType *s) {
    return (s->top == -1);
}
int is_full(StackType *s) {
    return (s->top == (MAZE_SIZE-1));
}
void push(StackType *s, element item) {
    if(is_full(s)) {
        fprintf(stderr,"is full\n");
        return;
    }
    else s->data[++(s->top)] = item;
}
element pop(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr,"is empty\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}
element peek(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr,"is empty\n");
        exit(1);
    }
    else return s->data[s->top];
    
}

element here = { 1, 0}, entry = {1,0};
char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'$','$','$','$','$','$'},
    {'e','0','0','0','$','$'},
    {'$','$','0','$','$','$'},
    {'$','$','0','$','$','$'},
    {'$','0','0','0','0','x'},
    {'$','$','$','$','$','$'},
};

void push_loc(StackType *s, int r, int c) {
    if(r<0||c<0) return;
    if(maze[r][c] != '$' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
    printf("\n");
    int r,c;
    for(r=0;r<MAZE_SIZE;r++) {
        for(c=0; c<MAZE_SIZE;c++)
            printf("%c",maze[r][c]);
        printf("\n");
    }
}
int main()
{
    int r,c ;
    StackType s;
    init_stack(&s);
    here = entry;
    element road[MAX_STACK_SIZE] = {};
    int i =0;
    while(maze[here.r][here.c] != 'x')
    {
        r = here.r;
        c = here.c;
        road[i].r= r;
        road[i++].c = c; //I don't need to add extra i++; if i do this
        maze[r][c] = '.';
        maze_print(maze);
        push_loc(&s,r-1,c);
        push_loc(&s,r+1,c);
        push_loc(&s,r,c-1);
        push_loc(&s,r,c+1);
        if(is_empty(&s)) {
            fprintf(stderr,"failed\n");
            return 0;
        }
        else here = pop(&s);
    }
    printf("got it!\n");
    for(int k =0; k < i; k++)
        printf("%d , %d \n", road[k].r,road[k].c);
    return 0;
}