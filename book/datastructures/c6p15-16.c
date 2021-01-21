#include<limits.h>
#include<stdlib.h>
#include<stdio.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
}ListNode;

ListNode *add_first(ListNode *head, element item) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = item;
    p->link = head;
    head = p;
    return head;
}
/* 15
void max_min(ListNode *head) {
    int max = INT_MIN, min = INT_MAX;
    ListNode *p = head;
    while(p != NULL) {
        if(max <= p->data) max = p->data;
        if(min >= p->data) min = p->data; 
        p = p->link;
    }
    printf(" max is %d, min is %d\n", max, min);
}
*/

ListNode *del_odd(ListNode *head) {
    head = head->link;
    ListNode *p = NULL, *removed = head;
    while(removed->link != NULL) {
        p = removed;
        removed = removed->link;
        p->link = removed->link;
        if(removed->link !=NULL)
            removed = removed->link;
        else break;
    }
    return head;
}
void print_list(ListNode *head) {
    for(ListNode *p = head; p!=NULL; p = p->link)
        printf("%d->",p->data);
    printf("NULL\n");
}
int main() {
    ListNode *head = NULL;
    head = add_first(head, 10);
    head = add_first(head, 20);
    head = add_first(head, 30);
    head = add_first(head, 40);
    head = add_first(head, 50);
    
    //max_min(head);
    head = del_odd(head);
    print_list(head);
    return 0;
}


