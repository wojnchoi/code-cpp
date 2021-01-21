#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char name[10];
    int age;
    double height;
}element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
}ListNode;

ListNode *add(ListNode *head, element item) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = item;
    if(head == NULL) {
        p->link = head;
        head = p;
    } else {
        ListNode *last = head;
        while(last->link != NULL)
            last = last->link;
        last->link = p;
    }
    return head;
}

void print_list(ListNode *head) {
    for(ListNode *p = head; p != NULL; p = p->link) {
        printf("name: %s \n", p->data.name);
        printf("age: %d \n", p->data.age);
        printf("age: %.1f \n", p->data.height);
        printf(" | \n");
    }
    printf("\n");
}

int main() {
    ListNode *head = NULL;
    element h1 = {"kim", 34, 1.7};
    element h2 = {"park", 27, 1.2};
    element h3 = {"lee", 48, 1.4};
    element h4 = {"choi", 30, 1.3};

    head = add(head, h1);
    head = add(head, h2);
    head = add(head, h3);
    head = add(head, h4);
    print_list(head);
    return 0;
}
