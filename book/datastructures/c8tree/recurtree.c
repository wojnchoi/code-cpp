#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode n1 = {5,NULL,NULL};
TreeNode n2 = {15,&n1,NULL};
TreeNode n3 = {22,NULL,NULL};
TreeNode n4 = {35,&n3,NULL};
TreeNode n6 = {95,NULL,NULL};
TreeNode n5 = {93, &n4,&n6};
TreeNode n7 = {17,&n2,&n5};
TreeNode *root = &n7;

//zhongwee
void inorder(TreeNode *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("[%d] ",root->data);
        inorder(root->right);
    }
}
//jeonwee
void preorder(TreeNode *root) {
    if(root != NULL) {
        printf("[%d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//whowee
void postorder(TreeNode *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ",root->data);
    }
}

int main() {
    printf("inorder ");
    inorder(root);
    printf("\n");

    printf("preorder ");
    preorder(root);
    printf("\n");

    printf("postorder ");
    postorder(root);
    printf("\n");
    return 0;
}