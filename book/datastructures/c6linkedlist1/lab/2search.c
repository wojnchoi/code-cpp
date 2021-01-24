#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;
}ListNode;

void error(const char *msg) {
    fprintf(stderr,"%s\n", msg);
    exit(1);
}
ListNode *insert_first(ListNode *head, element item) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = item;
    p->link = head;
    head = p;
    return head;
}
void print_list(ListNode *head) {
    for(ListNode *p = head;p!=NULL;p=p->link)
        printf("%d->",p->data);
    printf("NULL\n");
}
ListNode *search_list(ListNode *head, element x) {
    ListNode *p = head;
    while(p!=NULL) {
        if(p->data == x) return p;
        p = p->link;
    }
    return NULL;
}

int main() {
    ListNode *head = NULL;

    head = insert_first(head,10);
    print_list(head);
    head = insert_first(head,20);
    print_list(head);
    head = insert_first(head,30);
    print_list(head);
    if(search_list(head,30) !=NULL)
        printf("found it 30!\n");
    else 
        printf("not found\n");
    return 0;
}