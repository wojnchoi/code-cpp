#include<stdlib.h>
#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUE_SIZE 10

typedef int element;
typedef struct {
    element data[MAX_QUE_SIZE];
    int front, rear;
}QueType;

void error(char *msg) {
    fprintf(stderr,"%s\n", msg);
    exit(1);
}

void queue_init(QueType *q) {
    q->front = q->rear = 0;
}
int is_empty(QueType *q) {
    return (q->front == q->rear);
}
int is_full(QueType *q) {
    return ((q->rear+1)%MAX_QUE_SIZE == q->front);
}

void enque(QueType *q, element item) {
    if(is_full(q))
        error("full");
    q->rear = (q->rear+1)%MAX_QUE_SIZE;
    q->data[q->rear] = item;
}
element deque(QueType *q) {
    if(is_empty(q))
        error("empty");
    q->front = (q->front+1)%MAX_QUE_SIZE;
    return q->data[q->front];
}

#define MAX_VERTICES 50
int visited[MAX_VERTICES];
typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void graph_init(GraphType *g) {
    int r,c ;
    g->n=0;
    for(r=0;r<MAX_VERTICES;r++)
        for(c=0;c<MAX_VERTICES;c++)
            g->adj_mat[r][c]=0;
}

void insert_vertex(GraphType *g, int v) {
    if(((g->n)+1) > MAX_VERTICES) {
        fprintf(stderr,"overflow\n");
        return;
    }
    g->n++;
}
void insert_edge(GraphType *g, int start, int end) {
    if(start >= g->n || end >= g->n) {
        fprintf(stderr,"invalid\n");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}
void bfs_mat(GraphType *g, int v) {
    int w;
    QueType q;
    queue_init(&q);
    visited[v] = TRUE;
    printf("%d ->", v);
    enque(&q, v);
    while(!is_empty(&q)) {
        v= deque(&q);
        for(w = 0; w<g->n; w++) {
            if(g->adj_mat[v][w] && !visited[w]) {
                visited[w] = TRUE;
                printf("%d -> ", w);
                enque(&q, w);
            }
        }
    }   
}

int main() {
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);
    for(int i = 0; i < 6; i++)
        insert_vertex(g,i);

    insert_edge(g,0,1);
    insert_edge(g,0,2);
    insert_edge(g,0,3);
    insert_edge(g,1,4);
    insert_edge(g,1,2);
    insert_edge(g,4,3);

    printf("bfs : \n");
    bfs_mat(g, 2);
    printf("\n");
    return 0;
}