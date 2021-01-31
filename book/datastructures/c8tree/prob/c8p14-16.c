#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}TreeNode;

int sum_node(TreeNode *node) {
    if(node == NULL) {
        return 0;
    } else {
        int sum = node->data;
        sum += sum_node(node->left) + sum_node(node->right);
        return sum;
    }
}

void print_low_val(TreeNode *node, int val) {
    if(node == NULL) return;
    if(node->data < val) {
        printf("%d less than %d\n", node->data, val);
    }
    print_low_val(node->left,val);
    print_low_val(node->right,val);
}

int one_leaf_node(TreeNode *node) {
    int sum = 0;
    if(node == NULL) return 0;
    if((node->left == NULL && node->right != NULL) || (node->right == NULL && node->left != NULL)) {
        sum++;
    }
    sum += one_leaf_node(node->left);
    sum += one_leaf_node(node->right);
    return sum;
}

int node_max(TreeNode *node) {
    if (node == NULL) 
        return -214; 
  
    int max = node->data; 
    int lnode = node_max(node->left); 
    int rnode = node_max(node->right); 
    if (lnode > rnode) 
        max = lnode; 
    if (rnode > max) 
        max = rnode; 
    return max;
}
int main() {
    TreeNode n1 = {1,NULL,NULL};
    TreeNode n2 = {2,NULL,NULL};
    TreeNode n3 = {6,NULL,NULL};
    TreeNode n4 = {4,NULL,NULL};
    TreeNode n5 = {5,&n1,&n2};
    TreeNode n6 = {11,&n3,&n4};
    TreeNode n7 = {0,NULL,NULL};
    TreeNode n8 = {8,NULL,NULL};
    TreeNode n9 = {9,&n5,&n7};
    TreeNode n10 = {10,&n8,&n6};
    TreeNode n11 = {0, &n9,&n10};
    TreeNode *root = &n11;
    printf("%d\n", sum_node(root));
    printf("%d\n",one_leaf_node(root));
    printf("%d\n",node_max(root));
    print_low_val(root, 5);
    return 0;
}