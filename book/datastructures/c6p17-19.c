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
    if(head == NULL) { p->link = head; head = p; }
    else {
        ListNode *lastNode= head;
        while(lastNode->link != NULL) {
            lastNode = lastNode->link;
        }
        lastNode->link = p;
    }
    return head;
}

void print_list(ListNode *head) {
    for(ListNode *p = head; p!=NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}
/* 17
ListNode *alternate(ListNode *head, ListNode* head2, ListNode *r) {
    while(head || head2) {
        if(head != NULL) {
            r = add(r, head->data);
            head = head->link;
        }
        if(head2 != NULL) {
            r = add(r,head2->data);
            head2 = head2->link;
        }
    }
    return r;
}
*/

/* 18
ListNode *merge(ListNode* head, ListNode* head2) {
    ListNode* result = NULL;
    while(head || head2) {
        if(head != NULL && head2 != NULL) {
            if(head->data >= head2->data) {
                result = add(result,head2->data);
                head2 = head2->link;
            } else {
                result = add(result, head->data);
                head = head->link;
            }
        }
        if(head == NULL)
           { result = add(result, head2->data); head2 = head2->link; }
        else if(head2 == NULL) { result = add(result, head->data); head = head->link;}
    }
    return result;
}
*/
ListNode *split(ListNode*head, ListNode **A, ListNode **B) {
    ListNode *p = head;
    while(p != NULL) {
       *A = add(*A, p->data);
        if(p->link == NULL) break;
        p = p->link;
        if(p->link == NULL) break;
       *B = add(*B, p->data);
        p = p->link;
    }
    return head;
}
int main() {
    /* 17 18 19
    ListNode *head = NULL;
    ListNode *head2 = NULL;
    ListNode *result = NULL;
    head = add(head, 1);
    head = add(head, 5);
    head = add(head, 7);
    head = add(head, 9);
    print_list(head);

    head2 = add(head2, 0);
    head2= add(head2, 2);
    head2= add(head2, 10);
    head2= add(head2, 40);
    head2 = add(head2, 70);
    print_list(head2);
    */
    ListNode *A=NULL, *B=NULL, *C=NULL;
    C = add(C, 10);
    C = add(C, 20);
    C = add(C, 30);
    C = add(C, 40);
    C = add(C, 50);
    print_list(C);
    split(C,&A,&B);
    print_list(A);
    print_list(B);
    print_list(C);
    // result = alternate(head, head2, result);
    //result = merge(head,head2);
    return 0;
}