#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode *search(TreeNode *node, int key) {
    if (node == NULL) return NULL;
    if(key == node->key) return node;
    else if(key < node->key) return search(node->left,key);
    else return search(node->right,key);
}

TreeNode *new_node(int item) {
    TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = NULL; temp->right = NULL;
    return temp;
}

TreeNode *insert(TreeNode *node, int key) {
    if(node == NULL) return new_node(key);

    if(key < node->key) node->left = insert(node->left,key);
    else if(key > node->key) node->right = insert(node->right,key);

    return node;
}

TreeNode *min_val_node(TreeNode *node) {
    TreeNode * current = node;
    while(current->left != NULL)
        current = current->left;
    return current;
}

TreeNode *delete(TreeNode *root, int key) {
    if(root == NULL) return NULL;

    if(key < root->key) root->left = delete(root->left,key);
    else if(key > root->key) root->right = delete(root->right,key);
    else {
        if(root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            TreeNode * temp = root->left;
            free(root);
            return temp;
        }
        TreeNode *temp = min_val_node(root->right);
        root->key = temp->key;
        root->right = delete(root->right,temp->key);
    }
    return root;
}

void inorder(TreeNode *root) {
    if(root) {
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->left);
    }
}

int main() {
    TreeNode *root = NULL;
    TreeNode * temp = NULL;

    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 6);

    printf("binary search inorder\n");
    inorder(root);
    if(search(root,30) != NULL)
        printf("30 found\n");
    else
        printf(" not found\n");
    
    return 0;
}
