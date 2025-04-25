#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
struct Queue {
    int front, rear;
    int capacity;
    int* array;
};

// Function to create a queue of given capacity
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFull(struct Queue* queue) {
    return queue->rear == queue->capacity - 1;
}

// Enqueue an element to the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
}

// Dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; // Queue is now empty
    } else {
        queue->front++;
    }
    return value;
}

// Function to reverse the queue using recursion
void reverseQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return;
    }
    
    // Remove the front element
    int front = dequeue(queue);
    
    // Reverse the remaining queue recursively
    reverseQueue(queue);
    
    // Add the removed element to the rear of the queue
    enqueue(queue, front);
}

// Function to print the queue elements
void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(5);
    
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    
    printf("Original Queue: ");
    printQueue(queue);
    
    reverseQueue(queue);
    
    printf("Reversed Queue: ");
    printQueue(queue);
    
    return 0;
}
