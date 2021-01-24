#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element[50];
typedef struct DlistNode {
    element data; 
    struct DlistNode *llink;
    struct DlistNode *rlink;
}DlistNode;

DlistNode *current;

void init(DlistNode *phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DlistNode *head) {
    DlistNode *p;
    for(p = head->rlink; p!=head; p = p->rlink) {
        if(p==current) printf("<-| #%s# |-> ",p->data);
        else printf("<-| %s |-> ", p->data);
    }
    printf("\n");
}

void insert(DlistNode *before, element item) {
 DlistNode *newnode = (DlistNode*)malloc(sizeof(DlistNode));
 strcpy(newnode->data,item);
 newnode->llink = before;
 newnode->rlink = before->rlink;
 before->rlink->llink = newnode;
 before->rlink = newnode;
}

void delete(DlistNode *head, DlistNode *removed) {
    if(removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

int main() {
    char ch;
    DlistNode *head = (DlistNode*)malloc(sizeof(DlistNode));
    init(head);

    insert(head, "GangNam Style");
    insert(head, "Good Day");
    insert(head, "Mamamia");

    current = head->rlink;
    print_dlist(head);

    do {
        printf("\ncommand( <, >, q): ");
        ch = getchar();
        if(ch == '<') {
            current = current->llink;
            if(current == head)
                current = current->llink;
        }
        else if(ch == '>') {
            current = current->rlink;
            if(current == head) 
                current = current->rlink;
        }
        print_dlist(head);
        getchar();
    }while(ch!='q');
    return 0;
}
