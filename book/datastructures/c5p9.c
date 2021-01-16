#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_SIZE 10
typedef char element;
typedef struct {
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
	return ((q->rear+1)%MAX_SIZE == q->front);
}
void add_rear(Deq *q, element item) {
	if(is_full(q))
		error("full");
	q->rear = (q->rear +1) %MAX_SIZE;
	q->data[(q->rear)] = item;
}
element del_front(Deq *q) {
	if(is_empty(q)) 
		error("empty");
		q->front = (q->front+1) % MAX_SIZE;
		return q->data[q->front];
}
void add_front(Deq *q, element item) {
	if(is_full(q))
		error("full");
	q->data[(q->front)] = item;
	q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;
}
element del_rear(Deq *q) {
		if(is_full(q))
		error("full");
		int prev = q->rear;
		q->rear = (q->rear - 1 + MAX_SIZE)% MAX_SIZE;
		return q->data[prev];
}

int main() {
	Deq q;
	init_deq(&q);
	char arr[MAX_SIZE];
	printf("input: ");
	scanf("&s", arr);
	int i = 0;
	while(arr[i] != '\0') {
		if(arr[i] != '.' || arr[i] != ' ')
			add_rear(&q, tolower(arr[i]));
		i++;
	}
	
	while(!is_empty(&q)) {
		if(del_front(&q) != del_rear(&q))
			printf("no\n");
	}
	printf("yes\n");
	return 0;
}




















