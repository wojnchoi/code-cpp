#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}TreeNode;

int cal_dir_size(TreeNode *root) {
    int left_size, right_size;
    if(root == NULL) return 0;
    left_size = cal_dir_size(root->left);
    right_size = cal_dir_size(root->right);
    return (root->data + left_size + right_size);
}
int main() {
    TreeNode n5 = {500,NULL,NULL};
    TreeNode n4 = {200,NULL,NULL};
    TreeNode n3 = {100,&n5,&n4};
    TreeNode n2 = {50, NULL,NULL};
    TreeNode n1 = {0,&n3,&n2};
    TreeNode *dir = &n1;

    printf("file size %dMB\n", cal_dir_size(dir));
    return 0;
}