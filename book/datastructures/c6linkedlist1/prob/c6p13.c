#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
}ListNode;

ListNode *add(ListNode *head,element item) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = item;
    if(head == NULL) {
        p->link = head;
        head = p;
    } else {
        ListNode *last = head;
        while(last->link != NULL)
            last = last->link;
        last->link = p;
    }
    return head;
}

ListNode *del(ListNode *head, element item) {
    ListNode *removed = head, *p = NULL;
    while(removed->data != item) {
        p = removed;
        removed = removed->link;
    }
    if(p==NULL) head = head->link;
    else p->link = removed->link;

    free(removed);
    return head;
}

void print_list(ListNode *head) {
    for(ListNode *p=head; p!=NULL; p=p->link)
        printf("%d->",p->data);
    printf("NULL\n");
}
int main() {
    ListNode *head;
    head = add(head, 10);
    head = add(head, 20);
    head = add(head, 30);
    head = add(head, 40);
    head = add(head, 50);
    print_list(head);

    head = del(head, 50);
    print_list(head);
    return 0;
}