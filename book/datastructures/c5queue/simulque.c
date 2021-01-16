#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 5
typedef struct {
    int id;
    int arrival_time;
    int service_time;
} element;
typedef struct
{
    element data[MAX_SIZE];
    int front,rear;
} Que;

void error(const char *msg) {
    fprintf(stderr,"%s\n", msg);
    exit(1);
}
void init_que(Que *q) {
    q->front = 0;
    q->rear = 0;
}
int is_empty(Que *q) {
    return (q->front == q->rear);
}
int is_full(Que *q) {
    return ((q->rear + 1)%MAX_SIZE == q->front);
}
void enque(Que *q, element item) {
    if(is_full(q))
        error("full");
    q->rear = (q->rear + 1)%MAX_SIZE;
    q->data[q->rear] = item;
}
element deque(Que *q) {
    if(is_empty(q))
        error("empty");
    q->front = (q->front +1)%MAX_SIZE;
    return q->data[q->front];
}
element peek(Que *q) {
    if(is_empty(q))
        error("empty");
    return q->data[q->front];
}

int main() {
    int minutes = 60;
    int total_wait = 0;
    int total_customers = 0;
    int service_time = 0;
    int service_customer;
    Que queue;
    init_que(&queue);
    srand(time(NULL));

    for(int clock = 0; clock<minutes; clock++) {
        printf("time: %d\n", clock);
        if((rand()%10) < 3) {
            element customer;
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3+1;
            enque(&queue,customer);
            printf("customer %d enters at %d min. time stayed: %d\n",customer.id,customer.arrival_time,customer.service_time);
        }
        if(service_time > 0) {
            printf("customer %d online\n", service_customer);
            service_time--;
        } else {
            if(!is_empty(&queue)) {
                element customer = deque(&queue);
                service_customer = customer.id;
                service_time = customer.service_time;
                printf("customer %d start on %d. wait time was %d\n", customer.id,clock,clock-customer.arrival_time);
                total_wait += clock-customer.arrival_time;
            }
        }
    }
    printf("total time %d\n", total_wait);
    return 0;
}