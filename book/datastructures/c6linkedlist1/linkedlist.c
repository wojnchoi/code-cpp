#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
}ListNode;
void error(const char *msg) {
    fprintf(stderr,"%s\n",msg);
}
ListNode *insert_first(ListNode *head,element value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}
ListNode *insert(ListNode *head,ListNode *pre,element value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}
ListNode *del_first(ListNode *head) {
    ListNode *removed;
    if(head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}
ListNode *del(ListNode *head, ListNode *pre) {
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}
void print_list(ListNode *head) {
    for(ListNode *p=head;p!=NULL;p=p->link) {
        printf("%d->",p->data);
    }
    printf("\n");
}
element get_entry(ListNode *L, int index) {
    ListNode *p = L;
    for(int i = 0; i<index;i++) {
        p = p->link;
    }
    return p->data;
}
int get_length(ListNode *L) {
    ListNode *p = L;
    int cnt;
    while(p->link != NULL) {
        p = p->link;
        cnt++;
    }
    return cnt;
}
int main(void) {
    ListNode *head = NULL;
    for(int i=0;i<5;i++) {
        head = insert_first(head,i);
        print_list(head);
    }
    head = del_first(head);
    print_list(head);
    printf("%d\n", get_entry(head,1));
    printf("%d\n", get_length(head));
    return 0;
}