#include<stdio.h>
#include<stdlib.h>
#define max_list_size 100

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {
		new_node->link = *phead;
		*phead = new_node;
	}
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
	return;
}

void insert_node_back(ListNode** phead, ListNode* new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else {
		new_node->link = NULL;
		ListNode* p = *phead;
		while (p->link != NULL)
			p = p->link;
		p->link = new_node;
	}
}

void remove_node(ListNode** phead, ListNode* p, ListNode* removed) {
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
	return;
}

ListNode* create_node(element data) {
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(new_node));
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
}

void display(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

int main(void) {
	ListNode* list1 = NULL;
	int n, t;
	printf("노드의 개수 : ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("노드 #%d 데이터  : ", i + 1);
		scanf("%d", &t);
		insert_node_back(&list1, create_node(t));
	}
	printf("생성된 연결 리스트 : ");
	display(list1);
}
