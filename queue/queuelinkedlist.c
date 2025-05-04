#include <stdio.h>
#include<stdlib.h>

// Define the Node structure
struct Node {
    int data;        // Store the value of the node
    struct Node* next;  // Pointer to the next node in the list
};

// Function to enqueue an element into the queue
void enqueue(struct Node** f, struct Node** r, int val) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for a new node
    if (n == NULL) {
        printf("Queue is full\n");  // Handle memory allocation failure
    } else {
        n->data = val;  // Set the node's data
        n->next = NULL;  // Set the next pointer to NULL

        if (*f == NULL) {  // If the queue is empty (front is NULL)
            *f = *r = n;  // Both front and rear point to the new node
        } else {
            (*r)->next = n;  // Link the current rear to the new node
            *r = n;  // Move the rear pointer to the new node
        }
    }
}

// Function to traverse and print the linked list (queue)
void lltraversal(struct Node* ptr) {
    printf("Printing the elements of this linked list:\n");
    while (ptr != NULL) {
        printf("%d\n", ptr->data);  // Print the data of each node
        ptr = ptr->next;  // Move to the next node
    }
}

// Function to dequeue an element from the front of the queue
int dequeue(struct Node** f) {
    int val = -1;
    struct Node* ptr = *f;  // Pointer to the front of the queue
    if (*f == NULL) {
        printf("Queue is empty\n");  // Handle underflow (empty queue)
    } else {
        *f = (*f)->next;  // Move the front pointer to the next node
        val = ptr->data;  // Get the value from the front node
        free(ptr);  // Free the memory of the dequeued node
    }
    return val;  // Return the dequeued value (or -1 if empty)
}

int main() {
    struct Node *f = NULL;  // Front pointer of the queue (initially NULL)
    struct Node *r = NULL;  // Rear pointer of the queue (initially NULL)

    lltraversal(f);  // Print the current queue (empty initially)

    // Enqueue some elements
    enqueue(&f, &r, 45);
    enqueue(&f, &r, 49);
    enqueue(&f, &r, 5);
    enqueue(&f, &r, 875);

    // Print the queue after enqueueing elements
    lltraversal(f);

    // Dequeue elements and print the result
    printf("Dequeued: %d\n", dequeue(&f));
    printf("Dequeued: %d\n", dequeue(&f));

    return 0;  // End of the program
}
