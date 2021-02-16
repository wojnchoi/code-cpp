#include<stdio.h>
#include<stdlib.h>

#define MAX_VER 50
typedef struct GraphNode
{
    int vertex;
    struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
    int n;
    GraphNode *adj_list[MAX_VER];
}GraphType;

void init(GraphType *g) {
    int v;
    g->n = 0;
    for(v=0;v<MAX_VER;v++)
        g->adj_list[v] = NULL;
}
void insert_vertex(GraphType *g, int v) {
    if((g->n)+1 > MAX_VER) {
        fprintf(stderr,"graph overflow\n");
        return;
    }
    g->n++;
}
void insert_edge(GraphType *g, int u, int v) {
    GraphNode *node;
    if(u>=g->n || v >=g->n) {
        fprintf(stderr,"graph invalid");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}
void print_adj_list(GraphType *g) {
    for(int i = 0; i<g->n;i++) {
        GraphNode *p = g->adj_list[i];
        printf("%d list ", i);
        while (p!=NULL)
        {
            printf("-> %d ", p->vertex);
            p = p->link;
        }
        printf("\n");
        
    }
}
int get_degree(GraphType *g, int v) {
    int count = 0;
    for(GraphNode *p = g->adj_list[v]; p!= NULL; p = p->link) {
        count++;
    }
    return count;
}

int main() {
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i = 0; i<4; i++)
        insert_vertex(g,i);
    
    insert_edge(g,0,1);
    insert_edge(g,1,0);
    insert_edge(g,0,2);
    insert_edge(g,2,0);
    insert_edge(g,0,3);
    insert_edge(g,3,0);
    insert_edge(g,1,2);
    insert_edge(g,2,1);
    insert_edge(g,2,3);
    insert_edge(g,3,2);
    print_adj_list(g);
    printf("%d\n",get_degree(g, 1));
    free(g);
    return 0;
}