#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
typedef int element;
typedef struct {
    int data[SIZE];
    int size;
}prioritytype;

prioritytype *create() {
    return (prioritytype*)malloc(sizeof(prioritytype));
}
void init(prioritytype *p) {
    p->size = -1;
}
int is_empty(prioritytype *p) {
    return (p->size == -1);
}
int is_full(prioritytype *p) {
    return (p->size == SIZE);
}
void insert(prioritytype *p, element item) {
    if(!is_full(p))
    p->data[(p->size)++] = item;
}
element delete(prioritytype *p) {
    if(!is_empty(p)) {
        int prior = p->data[0];
        for(int i =1; i<=p->size; i++) {
            if(p->data[i] > prior) prior = p->data[i];
        }
        for(int i=prior; i < p->size-1; i++) {
            p->data[i] = p->data[i+1];
        }
        p->size--;
        return prior;
    }
    return -1;
}
element find(prioritytype *p) {
    if(!is_empty(p)) {
    int prior = p->data[0];
    for(int i =1; i<=p->size; i++) {
        if(p->data[i] > prior) prior = p->data[i];
    }
    return prior;
    }
    return -1;
}
int main() {
    prioritytype *p;
    p = create();
    init(p);
    insert(p, 10);
    insert(p, 5);
    insert(p, 3);
    insert(p, 2);
    insert(p, 20);
    printf("priority : %d\n", delete(p));
    return 0;
}