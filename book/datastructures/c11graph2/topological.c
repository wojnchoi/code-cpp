#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 50

typedef struct GraphNode {
    int vertex;
    struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
    int n;
    GraphNode *adj_mat[MAX_VERTICES];
}GraphType;
void graph_init(GraphType *g) {
    g->n = 0;
    int v;
    for(v=0; v<MAX_VERTICES;v++)
        g->adj_mat[v] = NULL;
}
void insert_vertex(GraphType *g, int v) {
    if(((g->n)+1)> MAX_VERTICES)
        return;

    g->n++;
}
void insert_edge(GraphType *g, int u, int v) {
    GraphNode *node;
    if(u >= g->n || v >= g->n)
        return;

    node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_mat[u];
    g->adj_mat[u]=node;
}
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct StackType {
    element stack[MAX_STACK_SIZE];
    int top;
}StackType;

void init(StackType *s) {
    s->top = -1;
}
int is_empty(StackType *s) {
    return s->top == -1;
}
int is_full(StackType *s) {
    return s->top == MAX_STACK_SIZE-1;
}
void push(StackType *s, element item) {
    if(is_full(s))
        return;
    else s->stack[++(s->top)] = item;
}
element delete(StackType *s) {
    if(is_empty(s))
        return;
    else return s->stack[(s->top)--];
}

int topo_sort(GraphType *g) {
    int i;
    StackType s;
    GraphNode *node;
    int *in_degree = (int*)malloc(g->n *sizeof(int));
    for(i = 0; i< g->n;i++)
        in_degree[i]= 0;
    for(i = 0; i<g->n;i++) {
        GraphNode *node = g->adj_mat[i];
        while(node != NULL) {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }

    init(&s);
    for(i=0; i<g->n; i++) {
        if(in_degree[i] == 0) push(&s, i);
    }
    while(!is_empty(&s)) {
        int w;
        w = delete(&s);
        printf("node %d ->", w);
        node  = g->adj_mat[w];
        while(node != NULL) {
            int u = node->vertex;
            in_degree[u]--;
            if(in_degree[u]==0) push(&s,u);
            node = node->link;
        }
    }
    free(in_degree);
    printf("\n");
    return (i == g->n);
}

int main() {
    GraphType g;
    graph_init(&g);

    insert_vertex(&g,0);
    insert_vertex(&g,1);
    insert_vertex(&g,2);
    insert_vertex(&g,3);
    insert_vertex(&g,4);
    insert_vertex(&g,5);

    insert_edge(&g,0,2);
    insert_edge(&g,0,3);

    insert_edge(&g,1,3);
    insert_edge(&g,1,4);

    insert_edge(&g,2,3);
    insert_edge(&g,2,5);

    insert_edge(&g,3,5);

    insert_edge(&g,4,5);

    topo_sort(&g);
    return 0;
}
