#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void reverseK(struct Node **pointer, int limit) {
    if (*pointer == NULL || limit == 1) return;

    struct Node *current = *pointer;
    struct Node *previous = NULL, *forward = NULL;
    struct Node *tail = NULL;
    int count = 0;

    while (current != NULL && count < limit) {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
        count++;
    }

    if (tail != NULL) {
        tail->next = current;
    }

    *pointer = previous;

    if (*pointer != NULL) {
        tail = *pointer;
        while (tail->next != NULL) {
            tail = tail->next;
        }
    }
}

void printList(struct Node *ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert(int num) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *trav = head;
        while (trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = newNode;
    }
}

int main() {
    int n, k, val;

    printf("Enter total number of elements: ");
    scanf("%d", &n);

    printf("Enter k value: ");
    scanf("%d", &k);

    printf("Input list values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(val);
    }

    reverseK(&head, k);
    printList(head);

    return 0;
}
