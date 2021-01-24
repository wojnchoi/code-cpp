#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
}ListNode;

void print_list(ListNode *head) {
    ListNode *p;
    if(head == NULL) return;
    p = head->link;
    do {
        printf("%d->", p->data);
        p = p->link;
    } while(p != head);
    printf("%d->\n",p->data);
}

ListNode *insert_fir(ListNode *head, element data) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if(head == NULL) {
        head = node;
        node->link = head;
    } else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}
ListNode *insert_las(ListNode *head, element data) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if(head ==NULL) {
        head = node;
        node->link = head;
    } else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

ListNode *search(ListNode *L, element data) {
    ListNode *p = L->link;
    for(;p!=L; p=p->link) {
        if(p->data == data) {
            return p;
        }
    }
    return NULL;
}
int get_size(ListNode *L) {
    ListNode *p = L->link;
    int cnt = 0;
    for(;p!=L;p =p->link) 
        cnt++;
    return cnt +1;
}
int main() {
    ListNode *head = NULL;
    ListNode *searchedNode = NULL;
    head = insert_fir(head, 1);
    head = insert_las(head, 2);
    head = insert_fir(head, 0);
    print_list(head);

    printf("%d\n", get_size(head));
    return 0;
}