#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct
{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}Deque;
void error(const char *msg) {
    fprintf(stderr,"%s\n",msg);
}
void init_deque(Deque *d) {
    d->front = d->rear = 0;
}
int is_empty(Deque *d) {
    return (d->front == d->rear);
}
int is_full(Deque *d) {
    return ((d->rear+1)%MAX_QUEUE_SIZE == d->front);
}

void deque_print(Deque *d) {
    printf("Deque(front=%d rear=%d) = ",d->front,d->rear);
    if(!is_empty(d)) {
        int i = d->front;
        do {
            i=(i+1)%MAX_QUEUE_SIZE;
            printf("%d | ",d->data[i]);
            if(i==d->rear)
                break;
        }while(i!=d->front);
    }
    printf("\n");
}
void add_rear(Deque *d,element item) {
    if(is_full(d))
        error("full");
    d->rear = (d->rear+1)%MAX_QUEUE_SIZE;
    d->data[d->rear] = item;
}
element delete_front(Deque *d) {
    if(is_empty(d))
        error("empty");
    d->front = (d->front+1)%MAX_QUEUE_SIZE;
    return d->data[d->front];
}
element get_front(Deque *d) {
    if(is_empty(d))
        error("empty");
    return d->data[(d->front+1)%MAX_QUEUE_SIZE];
}

void add_front(Deque *d, element item) {
    if(is_full(d))
        error("full");
    d->data[d->front] = item;
    d->front = (d->front-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
}
element delete_rear(Deque *d) {
    int prev = d->rear;
    if(is_empty(d))
        error("empty");
    d->rear = (d->rear -1 + MAX_QUEUE_SIZE) %MAX_QUEUE_SIZE;
    return d->data[prev];
}
element get_rear(Deque *d) {
    if(is_empty(d)) 
        error("empty");
    return d->data[d->rear];
}

int main() {
    Deque queue;
    init_deque(&queue);
    for(int i=0;i<3;i++) {
        add_front(&queue,i);
        deque_print(&queue);
    }
    for(int i=0;i<3;i++) {
        delete_rear(&queue);
        deque_print(&queue);
    }
    return 0;
}





