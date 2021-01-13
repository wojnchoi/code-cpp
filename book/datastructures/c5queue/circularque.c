#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct
{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QUEUE;

void error(const char *msg) {
    fprintf(stderr,"%s\n", msg);
    exit(1);
}
void init(QUEUE *q) {
    q->front = q->rear = 0;
}
int is_emtpy(QUEUE *q) {
    return (q->front == q->rear);
}
int is_full(QUEUE *q) {
    return ((q->rear + 1)%MAX_QUEUE_SIZE == q->front);
}

void que_print(QUEUE *q) {
    printf("QUEUE(front=%d rear=%d) = ", q->front,q->rear);
    if(!is_emtpy(q)) {
        int i = q->front;
        do
        {
            i=(i+1) % (MAX_QUEUE_SIZE);
            printf("%d | ",q->data[i]);
            if(i==q->rear)
                break;
        } while (i != q->front);
        
    }
    printf("\n");
}

void enque(QUEUE *q,element item) {
    if(is_full(q))
        error("queue full\n");
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}
element deque(QUEUE *q) {
    if(is_emtpy(q)) 
        error("queue empty\n");
    q->front = (q->front +1) %MAX_QUEUE_SIZE;
    return q->data[q->front];
}
element peek(QUEUE *q) {
    if(is_emtpy(q)) 
        error("queue empty\n");
    return   q->data[(q->front +1) %MAX_QUEUE_SIZE];
}
int main() {
    QUEUE queue;
    int element;

    init(&queue);
    printf("--data add--\n");
    while (!is_full(&queue))
    {
        printf("enter int: ");
        scanf("%d", &element);
        enque(&queue,element);
        que_print(&queue);
    }
    printf("que is full\n\n");

    printf("--data delete--\n");
    while(!is_emtpy(&queue)) {
        element = deque(&queue);
        printf("out : %d\n", element);
        que_print(&queue);
    }
    printf("que is empty\n");
    
    return 0;
}