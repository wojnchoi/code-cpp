#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[100];
} element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
}ListNode;

void error(const char *msg) {
    fprintf(stderr,"%s\n",msg);
    exit(1);
}
ListNode *insert_first(ListNode *head, element item) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = item;
    p->link = head;
    head = p;
    return head;
}
ListNode *insert(ListNode *head, ListNode *pre, element item) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = item;
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
    for(ListNode *p = head; p!=NULL;p=p->link) {
        printf("%s->", p->data.name);
    }
    printf("NULL \n");
}
int main() {
    ListNode *head =NULL;
    element data;

    strcpy(data.name, "KIWI");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "APPLE");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "WATERMELON");
    head = insert_first(head, data);
    print_list(head);

    return 0;
}
