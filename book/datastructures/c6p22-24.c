/*22
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
typedef int element;
typedef struct {
    element data[MAX_SIZE];
    int size;
}SortedListType;

void init(SortedListType *l) {
    l->size = 0;
}

int is_empty(SortedListType *l) {
    return (l->size == 0);
}
int is_full(SortedListType *l) {
    return (l->size == MAX_SIZE);
}
void add(SortedListType *l, element item) {
    if(!is_full(l)) {
        int i = 0;
        for(i = 0; i<l->size;i++) {
            if(l->data[i] > item) {
                for(int j=l->size; j > i; j--)
                    l->data[j] = l->data[j-1]; 
                break;
            }
        }
        l->data[i] = item;
        l->size++;
    }
}
void del(SortedListType *l, element item) {
    if(!is_empty(l)) {
        for(int i = 0; i < l->size; i++) {
            if(item == l->data[i])
                for(int j = i; j < l->size; j++)
                    l->data[j] = l->data[j+1];
        }
        l->size--;
    }
}
void clear(SortedListType *l) {
    while(!is_empty(l)) {
        int i = l->size;
        del(l,l->data[i]);
        i--;
    }
}
int is_in_list(SortedListType *l, element item) {
    for(int i=0; i < l->size; i++) {
        if(item == l->data[i]) {
            return 1;
        }
    }
    return 0;
}
int get_length(SortedListType *l) {
    return l->size;
}
void display(SortedListType *l) {
    for(int i = 0; i<l->size;i++)
        printf("%d->",l->data[i]);
    printf("\n");
}

int main() {
    SortedListType list;
    init(&list);
    add(&list, 10);
    add(&list, 30);
    add(&list, 20);
    add(&list, 50);
    add(&list, 60);
    display(&list);
    printf("30 is in the list?(1: yes 0: no) %d\n", is_in_list(&list,30));


    del(&list, 20);
    del(&list, 50);
    display(&list);
    printf("%d\n", get_length(&list));
    printf("30 is in the list?(1: yes 0: no) %d\n", is_in_list(&list,30));

    clear(&list);
    display(&list);
    printf("%d\n", get_length(&list));
    printf("30 is in the list?(1: yes 0: no) %d\n", is_in_list(&list,30));
}
*/
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct SortedList {
    element data;
    struct SortedList *link;
}SortedList;

int is_empty(SortedList *head) {
    return (head->link == NULL);
}

SortedList* add(SortedList *list, element item) {
    SortedList *p = (SortedList*)malloc(sizeof(SortedList));
    SortedList *head = list;
    p->data = item;
    while(head->link != NULL) {
        if(head->data > p->data) {
            for(SortedList* l = list; l!= head;l = l->link) {
                p->link = head;
                l->link = p;
                break;
            }
        }
        head = head->link;
    }
    return list;
}
void display(SortedList *head) {
    for(SortedList* p = head; p!=NULL; p = p->link)
        printf("%d->", p->data);
    printf("\n");
}
int main() {
    SortedList *head = NULL;
    head = add(head, 10);
    head = add(head, 20);
    head = add(head, 50);
    head = add(head, 30);
    head = add(head, 40);
    display(head);
    return 0;
}

/* 24 
typedef struct element {
    int row;
    int col;
    int value;
};
typedef struct ListNode {
    element data;
    struct ListNode* link;
}
*/