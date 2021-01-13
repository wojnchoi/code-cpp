#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QUEUE;

void error(char *msg) {
    fprintf(stderr,"%s\n", msg);
    exit(1);
}
void init(QUEUE *q) {
    q->front = -1;
    q->rear = -1;
}
void que_print(QUEUE *q) {
    for(int i=0; i<MAX_QUEUE_SIZE;i++) {
        if(i<=q->front || i > q->rear) printf(" | ");
        else printf("%d | ", q->data[i]);
    }
    printf("\n");
}
int is_full(QUEUE *q) {
    if(q->rear == MAX_QUEUE_SIZE -1)
        return 1;
    else 
        return 0;
}

int is_empty(QUEUE *q) {
    if(q->front == q->rear)
        return 1;
    else 
        return 0;
}
void enque(QUEUE *q, int item) {
    if(is_full(q)) {
        error("full\n");
        return;
    } q->data[++(q->rear)] = item;
}
int deque(QUEUE *q) {
    if(is_empty(q)) {
        error("empty\n");
        return -1;
    }
    int item = q->data[++(q->front)];
    return item;
}
int main(void) {
    int item = 0;
    QUEUE q;
    init(&q);

    enque(&q,10); que_print(&q);
    enque(&q,20); que_print(&q);
    enque(&q,30); que_print(&q);

    item = deque(&q); que_print(&q);
    item = deque(&q); que_print(&q);
    item = deque(&q); que_print(&q);
    return 0;
}
