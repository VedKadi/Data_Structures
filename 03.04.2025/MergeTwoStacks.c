#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top1 = NULL;
struct Node* top2 = NULL;

void push(struct Node** head, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = *head;
    *head = temp;
}

int pop(struct Node** head) {
    if (*head == NULL) {
        printf("Empty stack\n");
        return -999;
    }
    struct Node* temp = *head;
    int result = temp->data;
    *head = temp->next;
    free(temp);
    return result;
}

void displayMerged(struct Node* a, struct Node* b) {
    printf("Merged Output:\n");
    while (a != NULL) {
        printf("%d ", a->data);
        a = a->next;
    }
    while (b != NULL) {
        printf("%d ", b->data);
        b = b->next;
    }
    printf("\n");
}

int main() {
    push(&top1, 11);
    push(&top1, 22);
    push(&top1, 33);

    push(&top2, 44);
    push(&top2, 55);
    push(&top2, 66);

    printf("Popped from stack 1: %d\n", pop(&top1));
    printf("Popped from stack 2: %d\n", pop(&top2));

    printf("\n");
    displayMerged(top1, top2);

    return 0;
}
