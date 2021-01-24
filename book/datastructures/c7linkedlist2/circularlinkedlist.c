#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void print_list(ListNode *head) {
    ListNode *p;
    if(head == NULL) return;
    p = head->link;
    do {
        printf("%d->", p->data);
        p= p->link;
    } while(p!= head);
    printf("%d\n", p->data); //last node
}


ListNode *insert_first(ListNode *head, element item) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data =  item;
    if(head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode *insert_last(ListNode *head, element item) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = item;
    if(head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}
int get_length(ListNode *head) {
    ListNode*p = head->link;
    int cnt = 0;
    do {
        p = p->link;
        cnt++;
    } while(p != head);
    return (cnt += 1);
}

int main() {
    ListNode *head = NULL;

    head =insert_last(head,30);
    head =insert_last(head,40);
    head =insert_last(head,50);

    head = insert_first(head,20);
    head = insert_first(head,10);
    print_list(head);
    printf("%d\n",get_length(head));
    return 0;
}