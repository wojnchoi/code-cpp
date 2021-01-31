#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode temp;
    temp.val = 0; temp.next = NULL;
    struct ListNode* curr = &temp;
    int remainder = 0, sum;
    while (l1 != NULL || l2 != NULL || remainder != 0) {
        sum = remainder + (l1 == 0 ? 0 : l1->val) + (l2 == 0 ? 0: l2->val);
        remainder = sum/10;
        sum %= 10;
        curr->next = malloc(sizeof(struct ListNode));
        curr->next->next = NULL;
        curr->next->val = sum;
        curr = curr->next;
        l1 = (l1 == 0 ? 0 : l1->next);
        l2 = (l2 == 0 ? 0 : l2->next);
    }
    return temp.next;
}

struct ListNode *add(struct ListNode *head, int data) {
	struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
	p->val = data;
    p->next = head;
    head = p;
    return head;
}
void print_list(struct ListNode *head) {
	struct ListNode *p = head;
	while(p != NULL) {
		printf("%d->", p->val);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	struct ListNode *h1 = NULL, *h2 = NULL, *result = NULL;
	h1 = add(h1, 3);
	h1 = add(h1, 4);
	h1 = add(h1, 2);
	
	h2 = add(h2, 4);
	h2 = add(h2, 6);
	h2 = add(h2, 5);
	
	result = addTwoNumbers(h1,h2);
	print_list(h1);
	print_list(h2);
	print_list(result);
	return 0;
}


















