#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct
{
    element data[MAX_QUEUE_SIZE];
    int front,rear;
}QUEUE;
void error(const char *msg) {
    fprintf(stderr,"%s\n", msg);
    exit(1);
}
void init_que(QUEUE *q) {
    q->front = q->rear = 0;
}
int is_empty(QUEUE *q) {
    return (q->front == q->rear);
}
int is_full(QUEUE *q) {
    return ((q->rear+1)% MAX_QUEUE_SIZE == q->front);
}
void que_print(QUEUE *q){
    printf("(QUEUE front = %d, rear = %d) = ",q->front,q->rear);
    if(!is_empty(q)) {
        int i = q->front;
        do
        {
            i=(i+1)%MAX_QUEUE_SIZE;
            printf("%d |",q->data[i]);
            if(i==q->rear)
                break;
        } while (i!=q->front);
        
    }
    printf("\n");
}

void enque(QUEUE *q, element item) {
    if(is_full(q)) 
        error("que is full\n");
    q->rear = (q->rear +1)% MAX_QUEUE_SIZE;
    q->data[(q->rear)] = item;
}
element deque(QUEUE *q) {
    if(is_empty(q))
        error("que is empty\n");
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}
element peek(QUEUE *q) {
    if(is_empty(q))
        error("que is empty\n");
    return q->data[q->front];
}

int main() {
    QUEUE q;
    int element;
    init_que(&q);
    srand(time(NULL));
    for(int i =0;i<100;i++) {
        if(rand()%5==0)
            enque(&q,rand()%100);
        que_print(&q);
        if(rand()%10==0) {
            int data = deque(&q);
        }
        que_print(&q);
    }
    return 0;
}

