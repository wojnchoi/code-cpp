#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
}ListNode;

ListNode *add(ListNode *head, element item) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = item;
    p->link = head;
    head = p;
    return head;
}

int total(ListNode*head) {
    int total = 0;
    for(ListNode *p; p!=NULL; p = p->link) {
        total += p->data;
    }
    return total;
}

int main() {
    ListNode *head = NULL;
    int n, v;
    printf("node num: ");
    scanf("%d", &n);
    for(int i = 1; i<=n; i++) {
        printf("#%d val : ", i);
        scanf("%d", &v);
        head = add(head, v);
    }
    printf("node total data : %d\n", total(head));
    return 0;
}