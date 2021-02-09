#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct lltype {
    element data;
    struct lltype *next;
}lltype;

lltype *create() {
    return (lltype*)malloc(sizeof(lltype));
}
void init(lltype **head) {
    ((*head)->next) = NULL;
}
int is_empty(lltype *head) {
    return head == NULL;
}
int is_full(lltype *head) {
    //연결리스트라서 full이 될 방법은 malloc오작동?
    return 0;
}
void insert(lltype **head, element item) {
    lltype *temp = (lltype*)malloc(sizeof(lltype));
    temp->data = item;
    temp->next = NULL;

    lltype *start = (*head);
    if((*head)->data < item) {
        temp->next = *head;
        *head = temp;
    } else {
        while(start->next != NULL && start->next->data > item) {
            start=start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

element delete(lltype **head) {
    int data = -1;
    if(!is_empty(*head)) {
        lltype *temp = *head;
        (*head) = (*head)->next;
        data =  temp->data;
        free(temp);
    }
    return data;
}

element find(lltype *head) {
    return head->data;
}
int main() {
    
    lltype *head;
    head = create(head);
    init(&head);
    insert(&head,5);
    insert(&head,20);
    insert(&head,22);
    insert(&head,13);
    insert(&head,50);
    insert(&head,43);
    printf("%d\n",delete(&head));
    printf("%d\n",find(head));
    printf("%d\n",delete(&head));
    return 0;
}