#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *next;
    
}ListNode;

ListNode *add(ListNode *head, element item) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = item;
    if(head == NULL) {
        p->next = head;
        head = p;
    } else {
        ListNode *last = head;
        while(last->next != NULL)
            last = last->next;
        last->next = p;
    }
    return head;
}

int num_list(ListNode *head, element val) {
    int num = 0;
    for(ListNode *p = head; p != NULL; p = p->next) {
        if(val == p->data) num++;
    }
    return num;
}

int main() {
    ListNode *head = NULL;
    element n, v, l;
    printf("num node : ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        printf("#%d val : ", i);
        scanf("%d", &v);
        head = add(head,v);
    }
    printf("search val: "); scanf("%d", &l);
    printf("%d apeears %d time(s)\n", l, num_list(head,l));
    return 0;
}