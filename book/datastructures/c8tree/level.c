#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

#define MAX_SIZE 100
typedef TreeNode* element;
typedef struct {
    element data[MAX_SIZE];
    int front, rear;
}QueType;

void error(const char *msg) {
    fprintf(stderr,"%s\n", msg);
    exit(1);
}

void init(QueType *q) {
    q->rear = 0;
    q->front = 0;
}

int is_empty(QueType *q) {
    return (q->front == q->rear);
}

int is_full(QueType *q) {
    return ((q->rear +1)%MAX_SIZE == q->front);
}

void enque(QueType *q, element item) {
    if(is_full(q))
        error("full");
    q->rear = (q->rear+1)%MAX_SIZE;
    q->data[q->rear] = item;
}

element deque(QueType *q) {
    if(is_empty(q))
        error("empty");
    q->front = (q->front+1)%MAX_SIZE;
    return q->data[q->front];
}

void level_order(TreeNode *ptr) {
    QueType q;
    init(&q);
    if(ptr == NULL) return;
    enque(&q, ptr);
    while(!is_empty(&q)) {
        ptr = deque(&q);
        printf(" [%d] ", ptr->data);
        if(ptr->left)
            enque(&q,ptr->left);
        if(ptr->right)
            enque(&q, ptr->right);
    }
}
//     15
//   4    20
//  1    16 25
int main() {
    TreeNode n1 = {5, NULL,NULL};
    TreeNode n2 = {4, NULL, NULL};
    TreeNode n3 = {2, &n2,&n1};
    TreeNode n4 = {3, NULL,NULL};
    TreeNode n5 = {1, &n3,&n4};
    TreeNode *root = &n5;

    printf("level order ");
    level_order(root);
    printf("\n");
    return 0;
}