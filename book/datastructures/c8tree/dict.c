#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

typedef struct {
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
} element;

typedef struct TreeNode {
    element key;
    struct TreeNode *left, *right;
} TreeNode;

// el < e2 -1
// el > e2 = 1
// el == e2 = 0
int compare(element e1, element e2) {
    return strcmp(e1.word, e2.word);
}

void display(TreeNode *p) {
    if(p!=NULL) {
        printf("(");
        display(p->left);
        printf("%s:%s", p->key.word, p->key.meaning);
        display(p->right);
        printf(")");
    }
}

TreeNode *search(TreeNode *root, element key) {
    TreeNode *p = root;
    while(p!=NULL) {
        if(compare(key, p->key) == 0) return p;
        else if(compare(key,p->key) < 0) p = p->left;
        else if(compare(key, p->key) > 0) p = p->right;
    }
    return p;
}

TreeNode *new_node(element item) {
    TreeNode *p = (TreeNode*)malloc(sizeof(TreeNode));
    p->key = item;
    p->left = p->right = NULL;
    return p;
}

TreeNode *insert(TreeNode *node, element key) {
    if(node == NULL) return new_node(key);
    if(compare(key,node->key)<0) node->left = insert(node->left,key);
    else if(compare(key,node->key)>0) node->right = insert(node->right,key);
    return node;
}

TreeNode *min_val_node(TreeNode *node) {
    TreeNode *curr = node;
    while(curr->left != NULL) 
        curr = curr->left;
    return curr;
}

TreeNode *delete(TreeNode *root, element key) {
    if(root == NULL) return root;
    if(compare(key,root->key)<0) root->left = delete(root->left,key);
    else if(compare(key,root->key)>0) root->right = delete(root->right,key);
    else {
        if(root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        TreeNode *temp =  min_val_node(root->right);
        root->key = temp->key;
        root->right = delete(root->right,temp->key);
    }
    return root;
}

void help() {
    printf("\n**** i: insert, d: delete, s: search, p: print, q: quit ****: ");
}
int main() {
    char command;
    element e;
    TreeNode *root = NULL;
    TreeNode *temp;
    
    help();
    scanf("%c", &command);
    while(command != 'q') {
        help();
        scanf("%c", &command);
        switch(command) {
            case 'i': 
                printf("word: ");
                scanf("%s", e.word);
                printf("define: ");
                scanf("%s", e.meaning);
                root = insert(root,e);
                break;
            case 'd':
                printf("word: ");
                scanf("%s", e.word);
                root = delete(root,e);
                break;
            case 'p':
                display(root);
                printf("\n");
                break;
            case 's':
                printf("word: ");
                scanf("%s", e.word);
                temp = search(root,e);
                if(temp!=NULL) printf("meaning: %s\n", e.meaning);
                break;
        }
    }
    return 0;
}