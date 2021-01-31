#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
#define MAX_SIZE 100
typedef struct {
    int work_name;
    int work_time;
} element;
typedef struct
{
    element data[MAX_SIZE];
    int front, rear;
}Deq;
void error(const char *msg) {
    fprintf(stderr,"%s\n", msg);
    exit(1);
}
void init_deq(Deq *q) {
    q->front = 0;
    q->rear = 0;
}
int is_empty(Deq *q) {
    return (q->front == q->rear);
}
int is_full(Deq *q) {
    return ((q->rear + 1)%MAX_SIZE == q->front);
}
void add_rear(Deq *q, element item) {
    if(is_full(q))
        error("full");
    q->rear = (q->rear+1)%MAX_SIZE;
    q->data[q->rear] = item;
}
void add_front(Deq *q, element item) {
    if(is_full(q))
        error("full");
    q->data[q->front] = item;
    q->front = (q->front-1+MAX_SIZE)%MAX_SIZE;
}
element del_rear(Deq *q) {
    if(is_empty(q))
        error("empty");
    int prev = q->rear;
    q->rear = (q->rear-1+MAX_SIZE)%MAX_SIZE;
    return q->data[prev];
}
element del_front(Deq *q) {
    if(is_empty(q))
        error("empty");
    q->front = (q->front +1)%MAX_SIZE;
    return q->data[q->front];
}


void print_deq(Deq *q1) {

        printf("---------------------------------------------------------------------------\n");
    if(!is_empty(q1)) {
        int i = q1->front; 
        do {
            i=(i+1)%MAX_SIZE;
            printf("%d | ",q1->data[i].work_name);
            if(i==q1->rear)
                break;
            
        }while(i != q1->front);
    }
    printf("\n");
}
void ins_work(Deq *cpu1, Deq *cpu2, Deq *cpu3, element work) {
        int num = rand()%7+1;
        if(!is_full(cpu1) && !is_full(cpu2) && !is_full(cpu3)) {
            if(num == 1 || num==4) {
                printf("CPU1 STARTING job %d\n",work.work_name);
                add_rear(cpu1,work);
            }
            else if(num == 2 || num == 5) {
                printf("CPU2 STARTING job %d\n",work.work_name);
                add_rear(cpu2,work);
            }
            else if(num == 3 || num== 6){
                printf("CPU3 STARTING job %d\n",work.work_name);
                add_rear(cpu3,work);
            }
        }
}
void fin_work(Deq *w,Deq *w2,Deq *w3) {
    if(w->data[w->rear].work_time > 0 ) {
        w->data[w->rear].work_time -= 1;
    } else {
        if(!is_empty(w)) {
        printf("CPU1 FINISHED job %d\n", w->data[w->front+1].work_name);
        del_front(w);
        }
    }
    if(w2->data[w2->rear].work_time > 0 ) {
        w2->data[w2->rear].work_time -= 1;
    } else {
        if(!is_empty(w2)) {
        printf("CPU2 FINISHED job %d\n", w2->data[w2->front+1].work_name);
        del_front(w2);
        }
    }
    if(w3->data[w3->rear].work_time > 0 ) {
        w3->data[w3->rear].work_time -= 1;
    } else {
        if(!is_empty(w3)) {
        printf("CPU3 FINISHED job %d\n", w3->data[w3->front+1].work_name);
        del_front(w3);
        }
    }
}
int get_count(Deq *q) {
    if (q->front <= q->rear)
		return q->rear - q->front;
	else
		return MAX_SIZE - (q->front - q->rear);
}
void check_steal(Deq *cpu1,Deq *cpu2,Deq *cpu3) {
    if(!is_full(cpu1) && !is_full(cpu2) && !is_full(cpu3)) {
        if(is_empty(cpu1)) {
            if(get_count(cpu3)>1) {
                printf("CPU3 work %d to CPU1\n", cpu3->data[cpu3->rear].work_name);
                add_rear(cpu1,del_rear(cpu3));
            }else if(get_count(cpu2) > 1) {
                printf("CPU2 work %d to CPU1\n", cpu2->data[cpu2->rear].work_name);
                add_rear(cpu1,del_rear(cpu2));
            } 
        }
        if(is_empty(cpu2)) {
            if(get_count(cpu1) > 1) {
                printf("CPU1 work %d to CPU2\n", cpu1->data[cpu1->rear].work_name);
                add_rear(cpu2,del_rear(cpu1));
            } else if(get_count(cpu3)>1) {
                printf("CPU3 work %d to CPU2\n", cpu3->data[cpu3->rear].work_name);
                add_rear(cpu2,del_rear(cpu3));
            }
        }
        if(is_empty(cpu3)) {
            if(get_count(cpu2) > 1) {
                printf("CPU2 work %d to CPU3\n", cpu2->data[cpu2->rear].work_name);
                add_rear(cpu3,del_rear(cpu2));
            } else if(get_count(cpu1)>1) {
                printf("CPUl work %d to CPU3\n", cpu1->data[cpu1->rear].work_name);
                add_rear(cpu3,del_rear(cpu1));
            }
        }
    }
};
int main() {
    Deq cpu1,cpu2,cpu3;
    init_deq(&cpu1);
    init_deq(&cpu2);
    init_deq(&cpu3);

    srand(time(NULL));
    for(int i=1;i<=30;i++) {
        printf("elapsed sec %d\n",i);
        element work;
        work.work_time = rand() %5 + 2;
        work.work_name = i;

                print_deq(&cpu1);
                print_deq(&cpu2);
               print_deq(&cpu3);
        printf("---------------------------------------------------------------------------\n");
        fin_work(&cpu1,&cpu2,&cpu3);
        check_steal(&cpu1,&cpu2,&cpu3);
        ins_work(&cpu1,&cpu2,&cpu3,work);
        /*
                print_deq(w);
                print_deq(w2);
               print_deq(w3);
               */
        sleep(1);
        system("clear");
    }
    printf("\n");
    return 0;
}
