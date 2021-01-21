#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    int coef;
    int expon;
    struct ListNode *link;
}ListNode;
typedef struct ListType {
    int size;
    ListNode *head;
    ListNode *tail;
}ListType;

ListType *create() {
    ListType *plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

void insert_last(ListType *plist, int coef, int expon) {
    ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
    if(temp == NULL) {fprintf(stderr,"alloc error\n"); exit(1);}
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    if(plist->tail == NULL) {
        plist->head = plist->tail = temp;
    } else {
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}

void poly_add(ListType *plist1, ListType *plist2, ListType *plist3) {
    ListNode *a = plist1->head;
    ListNode *b = plist2->head;
    int sum;
    while(a&&b) {
        if(a->expon == b->expon) {
            sum = a->coef + b->coef;
            if(sum!=0) insert_last(plist3,sum,a->expon);
            a = a->link; b = b->link;
        } else if(a->expon > b->expon) {
            insert_last(plist3,a->coef,a->expon);
            a = a->link;
        } else {
            insert_last(plist3,b->coef,b->expon);
            b = b->link;
        }
    }
    for(;a!=NULL;a=a->link)
        insert_last(plist3,a->coef,a->expon);
    for(;b!=NULL;b=b->link)
        insert_last(plist3,b->coef,b->expon);
}


void poly_print(ListType *plist) {
    ListNode *p = plist->head;
    printf("poly: ");
    for(;p;p=p->link)
        printf("%dx^%d + ",p->coef,p->expon);
    printf("\n");
}

void poly_eval(ListType *plist, int val) {
    ListNode* p = plist->head;
    int sum = 1;
    int result = 0;
    while(p!=NULL) {
        if(p->expon > 1) {
        for(int i=1;i<=p->expon;i++)
            sum *=val;
            if(p->coef != 1) 
                sum *= p->coef;
        } else if(p->expon == 1) {
            sum = val*(p->coef);
        } else if(p->expon == 0) {
            sum = p->coef;
        }
        result += sum;
            sum = 1;
        p = p->link;
    }
    printf("%d\n", result);
}
int main() {
//    ListType *list1, *list2,*list3;
//    list1 = create();
//    list2 = create();
//    list3 = create();
//
//    insert_last(list1, 3,6);
//    insert_last(list1,7,3);
//    insert_last(list1,-2,2);
//    insert_last(list1,-9,0);
//
//    insert_last(list2, -2,6);
//    insert_last(list2,-4,4);
//    insert_last(list2,6,2);
//    insert_last(list2,6,1);
//    insert_last(list2,1,0);
//
//    poly_print(list1);
//    poly_print(list2);
//    poly_add(list1,list2,list3);
//    poly_print(list3);
    ListType *list1;
    list1 = create();
    insert_last(list1, 1,3);
    insert_last(list1, 2, 1);
    insert_last(list1, 6,0);
    poly_print(list1);
    poly_eval(list1, 2);
    return 0;
}