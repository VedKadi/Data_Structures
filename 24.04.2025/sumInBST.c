#include <stdio.h>
#include <stdlib.h>

// Definition of the BST Node
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

// Function to insert a new node in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Inorder traversal to get sorted elements from BST
void inorder(struct Node* root, int arr[], int* index) {
    if (root != NULL) {
        inorder(root->left, arr, index);
        arr[*index] = root->data;
        (*index)++;
        inorder(root->right, arr, index);
    }
}

// Function to find two numbers whose sum equals the target
void findPairWithSum(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            printf("Pair found: %d and %d\n", arr[left], arr[right]);
            return;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    printf("No such pair found.\n");
}

int main() {
    struct Node* root = NULL;
    int target, n = 0;

    // Insert nodes into the BST
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);

    // Input the target sum
    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Step 1: Perform inorder traversal to get sorted array
    int arr[100], index = 0;
    inorder(root, arr, &index);

    // Step 2: Use two-pointer technique to find the pair
    findPairWithSum(arr, index, target);

    return 0;
}
