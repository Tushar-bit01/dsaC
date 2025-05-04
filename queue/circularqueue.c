#include <stdio.h>
#include <stdlib.h>

// Define a structure for the circular queue
struct cqueue {
    int f;       // Front pointer
    int r;       // Rear pointer
    int size;    // Size of the queue
    int* arr;    // Array to store elements of the queue
};

// Function to enqueue (insert) an element into the circular queue
void enqueue(struct cqueue* q, int val) {
    // Check if the queue is full (when rear+1 is equal to front, modulo size)
    if ((q->r + 1) % (q->size) == q->f) {
        printf("Queue overflow\n");  // If full, print overflow message
    } else {
        // If not full, move the rear pointer to the next position (circularly) and insert the value
        q->r = (q->r + 1) % (q->size);
        q->arr[q->r] = val;
    }
}

// Function to dequeue (remove) an element from the circular queue
int dequeue(struct cqueue* q) {
    int a = -1;  // Initialize a variable to hold the dequeued value
    // Check if the queue is empty (front equals rear)
    if (q->r == q->f) {
        printf("Queue underflow\n");  // If empty, print underflow message
    } else {
        // If not empty, move the front pointer to the next position (circularly)
        q->f = (q->f + 1) % (q->size);
        a = q->arr[q->f];  // Store the value of the element at the front
    }
    return a;  // Return the dequeued value (or -1 if underflow)
}

int main() {
    // Create and initialize the circular queue
    struct cqueue* q = (struct cqueue*)malloc(sizeof(struct cqueue));
    q->size = 100;  // Set the size of the queue
    q->f = q->r = 0;  // Initialize front and rear pointers to 0
    q->arr = (int*)malloc(q->size * sizeof(int));  // Allocate memory for the queue array

    // Enqueue some elements into the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    // Dequeue and print the removed elements
    printf("Dequeued: %d\n", dequeue(q));  // Dequeues 10
    printf("Dequeued: %d\n", dequeue(q));  // Dequeues 20

    // Enqueue more elements, demonstrating circular behavior
    enqueue(q, 50);
    enqueue(q, 60);  // This should work even though the front is at index 2

    // Dequeue and print the remaining elements
    printf("Dequeued: %d\n", dequeue(q));  // Dequeues 30
    printf("Dequeued: %d\n", dequeue(q));  // Dequeues 40
    printf("Dequeued: %d\n", dequeue(q));  // Dequeues 50
    printf("Dequeued: %d\n", dequeue(q));  // Should print underflow since the queue is empty

    return 0;
}
