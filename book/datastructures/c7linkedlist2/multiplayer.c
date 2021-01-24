#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element[15];
typedef struct ListNode {
    element data;
    struct ListNode *link;
}ListNode;

ListNode *insert_first(ListNode *head, element item) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    strcpy(node->data, item);  
    if(head == NULL) {
        head = node;
        node->link = head;
    } else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

int main() {
    ListNode *head =NULL;
    head = insert_first(head, "KIM");
    head = insert_first(head, "CHOI");
    head = insert_first(head, "PARK");

    ListNode *p = head;
    for(int i = 0; i<20; i++) {
        printf("turn: %s\n", p->data);
        p=p->link;
    }
    return 0;
}