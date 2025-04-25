#include <stdio.h>
#include <stdlib.h>

struct Item {
    int data;
    struct Item* next;
} *first = NULL, *second = NULL, *sumList = NULL;

void createList(struct Item **head, int n) {
    struct Item *curr, *temp;
    *head = (struct Item*) malloc(sizeof(struct Item));

    (*head)->next = NULL;
    scanf("%d", &(*head)->data);
    curr = *head;

    for (int i = 1; i < n; i++) {
        temp = (struct Item*) malloc(sizeof(struct Item));
        scanf("%d", &temp->data);
        temp->next = NULL;
        curr->next = temp;
        curr = temp;
    }
}

void showList(struct Item *ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void addLists(struct Item *x, struct Item *y) {
    struct Item *curr, *temp;

    if (x == NULL) {
        sumList = y;
        return;
    }

    if (y == NULL) {
        sumList = x;
        return;
    }

    while (x && y) {
        if (sumList == NULL) {
            sumList = (struct Item*) malloc(sizeof(struct Item));
            sumList->data = x->data + y->data;
            curr = sumList;
            curr->next = NULL;
        } else {
            temp = (struct Item*) malloc(sizeof(struct Item));
            temp->data = x->data + y->data;
            temp->next = NULL;
            curr->next = temp;
            curr = temp;
        }

        x = x->next;
        y = y->next;
    }
}

int main() {
    int n1, n2;

    scanf("%d", &n1);
    createList(&first, n1);

    scanf("%d", &n2);
    createList(&second, n2);

    printf("After Addition:\n");
    addLists(first, second);
    showList(sumList);

    return 0;
}
