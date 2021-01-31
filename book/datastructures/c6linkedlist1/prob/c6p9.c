#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

void error(const char *msg) {
    fprintf(stderr,"%s\n", msg);
    exit(1);
}

ListNode *insert_last(ListNode *head, element item) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = item;
    p->link = NULL;
    if(head == NULL) {
        p->link = head;
        head = p;
    } else {
        ListNode *lastNode = head;
        while(lastNode->link!= NULL)
            lastNode = lastNode->link;
        lastNode->link = p;
    }
    return head;
}

void print_list(ListNode *head) {
    ListNode *p = head;
    while(p!=NULL) {
        printf("%d->",p->data);
        p=p->link;
    }
    printf("\n");
    
}
int main() {
    ListNode *head = NULL;
    int n, v;
    printf("num of node: ");
    scanf("%d", &n);
    for(int i = 1; i<= n;i++) {
        printf("node %d data: ", i);
        scanf("%d", &v);
        head = insert_last(head,v);
    }
    printf("output: ");
    print_list(head);
    return 0;
}