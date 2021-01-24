#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct DlistNode {
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
} DlistNode;

void init(DlistNode *phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DlistNode *phead) {
    DlistNode *p;
    for(p=phead->rlink; p != phead; p = p->rlink) {
        printf("<-| |%d| |-> ", p->data);
    }
    printf("\n");
}

void dinsert(DlistNode *before, element item) {
    DlistNode *newnode = (DlistNode*)malloc(sizeof(DlistNode));
    newnode->data = item;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddel(DlistNode *head, DlistNode *removed) {
    if(removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

int main() {
    DlistNode *head = (DlistNode*)malloc(sizeof(DlistNode));
    init(head);
    printf("adding\n");
    for(int i = 0; i < 5; i++) {
        dinsert(head, i);
        print_dlist(head);
    }
    printf("\nremoving\n");
    for(int i = 0; i< 5; i++){
        print_dlist(head);
        ddel(head,head->rlink);
    }
    free(head);
    return 0;
}