#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct DlistNode {
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
}DlistNode;

void init(DlistNode *head) {
    head->llink = head;
    head->rlink = head;
}
void print_list(DlistNode *head) {
    DlistNode *p;
    for(p=head->rlink;p!=head;p=p->rlink) {
        printf("<-| %d |-> ", p->data);
    }
    printf("\n");
}

void insert(DlistNode *before, element data) {
    DlistNode *newnode = (DlistNode*)malloc(sizeof(DlistNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void delete(DlistNode *head, DlistNode *removed) {
    if(removed == NULL) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

DlistNode *search(DlistNode *L, element data) {
    DlistNode* p;
	for (p = L->rlink;p!=L;p=p->rlink) {
		if (p->data == data)
			return p;
	}
	return NULL;
}
int main() {
    DlistNode *head = (DlistNode*)malloc(sizeof(DlistNode));
    init(head);

    int n, val;
    printf("enter data: ");
    scanf("%d", &n);
    for(int i = 1; i<=n; i++) {
        printf("node #%d data: ", i);
        scanf("%d", &val);
        insert(head, val);
    }
    print_list(head);
    print_list(search(head, 4));
    return 0;
}
