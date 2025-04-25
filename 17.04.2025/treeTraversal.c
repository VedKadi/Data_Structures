#include<stdio.h>
#include<stdlib.h>
//Binary tree
//structure
struct node{
    int data;
    struct node* left;
    struct node* right;
};
//create node function that returns address of the created node
struct node* createNode(int data){
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left =  n->right = NULL;
    return n;
}
//Pre Order Traversal
void preOrder(struct node* root){
    if(root != NULL){
        printf(" %d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
//Post Order Traversal
void postOrder(struct node* root){
    if(root != 0){
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ",root->data);
    }
}
//In Order Traversal
void inOrder(struct node* root){
    if(root != NULL){
        inOrder(root->left);
        printf(" %d ",root->data);
        inOrder(root->right);
    }
}
int main(){
    struct node* p = createNode(45);
    struct node* pl = createNode(90);
    struct node* pr = createNode(180);
    struct node* pll = createNode(71);
    struct node* plr = createNode(69);
    struct node* prr = createNode(47);
    struct node* prl = createNode(88);
    p->left = pl;
    p->right = pr;
    pl->left = pll;
    pl->right = plr;
    pr->left = prl;
    pr->right = prr;
    preOrder(p);
    postOrder(p);
    inOrder(p);
}