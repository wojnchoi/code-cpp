#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];

void init(GraphType *g) {
    int r,c;
    g->n = 0;
    for(r = 0; r<MAX_VERTICES; r++) {
        for(c = 0; c<MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

void insert_vertex(GraphType *g, int v) {
    if(((g->n)+1) > MAX_VERTICES) {
        fprintf(stderr,"full");
        return;
    }
    g->n++;
}
void insert_edge(GraphType *g, int start, int end) {
    if(start>=g->n || end >= g->n) {
        fprintf(stderr,"invalid\n");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void dfs_mat(GraphType *g, int v) {
    int w;
    visited[v] = TRUE;
    printf("vertice %d-> ", v);
    for(w=0;w<g->n;w++) {
        if(g->adj_mat[v][w] && !visited[w])
            dfs_mat(g,w);
    }
}

int main() {
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i = 0; i < 5; i++)
        insert_vertex(g,i);

    insert_edge(g,0,1);
    insert_edge(g,0,2);
    insert_edge(g,0,3);
    insert_edge(g,1,4);
    insert_edge(g,1,2);
    insert_edge(g,3,4);

    printf("depth first search\n");
    dfs_mat(g,0);
    printf("\n");
    return 0;
}

