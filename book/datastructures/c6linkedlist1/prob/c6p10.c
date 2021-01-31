#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
}ListNode;

ListNode *insert_first(ListNode* head, element val) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = val;
    p->link = head;
    head = p;
    return head;
}
int num_node(ListNode* head) {
    int count = 0;
    for(ListNode *p=head; p != NULL; p = p->link) {
        count++;
    }
    return count;
}

int main() {
    ListNode *head = NULL;
    int n, v;
    printf("num of node: ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        printf("node #%d value: ", i);
        scanf("%d", &v);
        head = insert_first(head, v);
    }
    printf("linked list node count : %d\n",num_node(head)); 
    return 0;
}