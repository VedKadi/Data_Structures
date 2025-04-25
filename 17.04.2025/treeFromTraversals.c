#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the index of the root node in inorder traversal
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

// Recursive function to construct the tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    // Get the root from the last element of postorder
    int rootValue = postorder[*postIndex];
    struct Node* root = createNode(rootValue);
    (*postIndex)--;  // Decrement postIndex for next root

    if (start == end)
        return root;

    // Find the index of the root in inorder
    int rootIndex = findIndex(inorder, start, end, rootValue);

    // Recursively construct the right subtree and left subtree
    root->right = buildTree(inorder, postorder, rootIndex + 1, end, postIndex);
    root->left = buildTree(inorder, postorder, start, rootIndex - 1, postIndex);

    return root;
}

// Function for inorder traversal to check correctness
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Inorder Traversal of the constructed tree:\n");
    inorderTraversal(root);

    return 0;
}
