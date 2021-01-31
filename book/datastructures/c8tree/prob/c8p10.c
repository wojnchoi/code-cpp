#include<stdio.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode *inorder(TreeNode *root) {
    if(root !=NULL) {
        inorder(root->left);
        printf("%d-> ", root->data);
        inorder(root->right);
    }
}
TreeNode *preorder(TreeNode *root) {
    if(root !=NULL) {
        printf("%d-> ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
TreeNode *postorder(TreeNode *root) {
    if(root !=NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d-> ", root->data);
    }
}

int main() {
    TreeNode n1 = {1,NULL,NULL};
    TreeNode n2 = {3,NULL,NULL};
    TreeNode n3 = {8,NULL,NULL};
    TreeNode n4 = {11,NULL,NULL};
    TreeNode n5 = {2,&n1,&n2};
    TreeNode n6 = {10,&n3,&n4};
    TreeNode n7 = {5,NULL,NULL};
    TreeNode n8 = {7,NULL,NULL};
    TreeNode n9 = {4,&n5,&n7};
    TreeNode n10 = {9,&n8,&n6};
    TreeNode n11 = {6, &n9,&n10};
    TreeNode *root = &n11;

    root = postorder(root);

    return 0;
}