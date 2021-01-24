#include<stdio.h>
#include<stdlib.h>

typedef int element; 
typedef struct QueNode {
    element data;
    struct QueNode *link;
}QueNode;
typedef struct {
    QueNode *front, *rear;
}LinkedQueType;

void init(LinkedQueType *q) {
    q->front = NULL;
    q->rear = NULL;
}
int is_empty(LinkedQueType *q) {
    return (q->front == NULL);
}
void enqueue(LinkedQueType *q, element data) {
    QueNode *temp = (QueNode*)malloc(sizeof(QueNode));
    temp->data = data;
    temp->link = NULL;
    if(is_empty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->link = temp;
        q->rear = temp;
    }
}

element dequeue(LinkedQueType *q) {
    QueNode *temp = q->front;
    element data;
    if(is_empty(q)) {
        fprintf(stderr,"empty\n");
        exit(1);
    } else {
        data = temp->data;
        q->front = q->front->link;
        if(q->front == NULL) q->rear = NULL;
        free(temp);
        return data;
    }
}

void print_que(LinkedQueType *q) {
    QueNode *p;
    for(p=q->front;p!=NULL; p=p->link)
        printf("%d->",p->data);
    printf("NULL\n");
}
int main() {
    LinkedQueType que;
    init(&que);

    enqueue(&que,1); print_que(&que);
    enqueue(&que,2); print_que(&que);
    enqueue(&que,3); print_que(&que);
    dequeue(&que); print_que(&que);
    dequeue(&que); print_que(&que);
    dequeue(&que); print_que(&que);
    return 0;
}