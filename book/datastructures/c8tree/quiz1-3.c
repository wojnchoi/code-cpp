#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}TreeNode;

int get_node_count(TreeNode *root) {
    int count = 0;
    if(root != NULL) {
        count = 1 + get_node_count(root->left) + get_node_count(root->right);
    }
    return count;
}

int get_leaf_count(TreeNode *root) {
    int count = 0;
    if(root != NULL) {
        if(root->left == NULL && root->right == NULL) return 1;
        else count = get_leaf_count(root->left) + get_leaf_count(root->right);
    }
    return count;
}

int get_height(TreeNode *root) {
    int height = 0;
    if(root != NULL) {
        height = 1 + max(get_height(root->left),get_height(root->right));
    }
    return height;
}

int get_nonleaf_count(TreeNode *t) {
    int count = 0;
    if(t != NULL) {
        if(t->left == NULL && t->right == NULL) return 0;
        else count = 1 + get_nonleaf_count(t->left) + get_nonleaf_count(t->right);
    }
    return count;
}

int equal(TreeNode *a, TreeNode *b) {
    if (a==NULL && b==NULL) 
        return 1; 
  
    /* 2. both non-empty -> compare them */
    if (a!=NULL && b!=NULL) 
    { 
        return
        ( 
            a->data == b->data && 
            equal(a->left, b->left) && 
            equal(a->right, b->right) 
        ); 
    } 
      
    /* 3. one empty, one not -> false */
    return 0;
}
int main() {
    TreeNode n1 = {4,NULL,NULL};
    TreeNode n2 = {5,NULL,NULL};
    TreeNode n3 = {2,&n1,&n2};
    TreeNode n4 = {6,NULL,NULL};
    TreeNode n5 = {3,&n4,NULL};
    TreeNode n6 = {1,&n3,&n5};
    TreeNode *root = &n6;

    TreeNode n7 = {4,NULL,NULL};
    TreeNode n8 = {5,NULL,NULL};
    TreeNode n9 = {2,&n7,&n8};
    TreeNode n10 = {6,NULL,NULL};
    TreeNode extra2 = {20, NULL,NULL};
    TreeNode extra1 = {10, &extra2, NULL};
    TreeNode n11 = {3,&n10,&extra1};
    TreeNode n12 = {1,&n9,&n11};
    TreeNode *root2 = &n12;
    printf("%d\n", get_node_count(root2));
    printf("%d\n", get_leaf_count(root2));
    printf("%d\n", get_height(root2));
    printf("%d\n", get_nonleaf_count(root2));
    printf("%d\n",equal(root,root2));
    return 0;
}