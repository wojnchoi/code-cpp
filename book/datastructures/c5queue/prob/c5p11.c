#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_SIZE 10
typedef char element;
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
    q->front = q->rear = 0;
}
int is_full(Deq *q) {
    return ((q->rear+1)%MAX_SIZE == q->front);
}
int is_empty(Deq *q) {
    return (q->front == q->rear);
}
void add_rear(Deq *q, element item) {
    if(is_full(q)) 
        error("full");
    q->rear = (q->rear +1)%MAX_SIZE;
    q->data[(q->rear)] = item;
}
element del_rear(Deq *q) {
    int prev = q->rear;
    if(is_empty(q))
        error("empty");
    else {
        q->rear = (q->rear -1 +MAX_SIZE)%MAX_SIZE;
        return q->data[prev];
    }
}
element del_front(Deq *q) {
    if(is_empty(q))
        error("empty");
    else {
        q->front = (q->front +1)%MAX_SIZE;
        return q->data[(q->front)];
    } 
        
}

int main() {

    element word[MAX_SIZE];
    Deq q;
    init_deq(&q);

    printf("checker: ");
    scanf("%s", word);

    int i = 0, result = 1;
    while(word[i] != '\0') {
        add_rear(&q,word[i]);
        i++;
    }
    while((i%2!=1 || i%2==0) && i >= 0) {
        if(!is_empty(&q)) {
            element a = del_rear(&q);
            element b = del_front(&q);
            if(a != b)
                result = 0;
        }
        i -= 2;
    }
    if(result == 1)
        printf("palindrome\n");
    else 
        printf("not palindrome\n");
    return 0;
}
