#include<stdio.h>
#include<stdlib.h>

#define MAX_VER 50
typedef struct GraphType {
    int n;
    int adj_mat[MAX_VER][MAX_VER];
}GraphType;

void init(GraphType *g) {
    int r,c;
    g->n = 0;
    for(r = 0; r<MAX_VER;r++)
        for(c = 0; c<MAX_VER;c++)
            g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType *g, int v) {
    if((g->n)+1 > MAX_VER) {
        fprintf(stderr,"graph overflow\n");
        return;
    }
    g->n++;
}
void insert_edge(GraphType *g, int start, int end) {
    if(start>=g->n || end > g->n) {
        fprintf(stderr,"unvalid\n");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}
void print_adj_mat(GraphType *g) {
    for(int i = 0; i< g->n; i++) {
        for(int j = 0; j<g->n; j++)
            printf("%2d ", g->adj_mat[i][j]);
        printf("\n");
    }
}
int get_degree(GraphType *g, int v) {
    int count = 0;
    for(int i = 0; i<g->n; i++) {
        if(g->adj_mat[v][i] == 1) {
                count++;
        }
    }
    return count;
}
void main() {
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i = 0; i<4; i++)
        insert_vertex(g, i);
    insert_edge(g,0,1);
    insert_edge(g,0,2);
    insert_edge(g,0,3);
    insert_edge(g,1,2);
    insert_edge(g,2,3);
    print_adj_mat(g);
    printf("%d\n", get_degree(g,0 ));
    printf("%d\n", get_degree(g,1));
    printf("%d\n", get_degree(g,2));
    printf("%d\n", get_degree(g,3));
    free(g);

}
