#include<stdio.h>
#include<stdlib.h>
//Binary tree
//structure
struct node{
    int data;
    struct node* left;
    struct node* right;
};
//Count the total no. of nodes
int countNodes(struct node* root){
    if(root == NULL){
        return(0);
    }
    int l = countNodes(root->left);
    int r = countNodes(root->right);
    return(r+l+1); 
}

//Function to count the no. of leaf nodes
int countLeafNodes(struct node* root){
    if(root->left == NULL && root->right == NULL){
        return(1);
    }
    int c = countLeafNodes(root->left) + countLeafNodes(root->right);
    return(c);
}
//Function to calculate height of binary tree
int height(struct TreeNode* node) {
    if (node == NULL)
        return 0;

    int left = height(node->left);
    int right = height(node->right);

    if (left > right)
        return left + 1;
    else
        return right + 1;
}