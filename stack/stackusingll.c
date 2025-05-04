#include <stdio.h>
#include <stdlib.h>

// Define a structure for the stack using linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node
};

// Function to push an element onto the stack
struct Node* push(struct Node* top, int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for a new node
    if (n == NULL) {  // Check if memory allocation was successful
        printf("Stack overflow\n");  // If memory allocation fails, print overflow message
    } else {
        n->data = data;      // Set the data of the new node
        n->next = top;       // Link the new node to the current top of the stack
        top = n;             // Update the top pointer to point to the new node
        return top;          // Return the updated top
    }
    return top; // If memory allocation failed, return the original top
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {  // Check if the stack is empty (top is NULL)
        printf("Stack underflow\n");  // If empty, print underflow message
        return -1;  // Return -1 to indicate underflow
    } else {
        struct Node* p = *top;  // Save the current top node
        *top = (*top)->next;     // Move the top pointer to the next node
        int val = p->data;       // Save the data of the popped node
        free(p);                 // Free the memory allocated for the popped node
        return val;              // Return the popped value
    }
}

// Function to traverse and print the stack (linked list)
void lltraversal(struct Node* ptr) {
    while (ptr != NULL) {         // Traverse until we reach the end of the stack
        printf("%d\n", ptr->data); // Print the data of the current node
        ptr = ptr->next;           // Move to the next node
    }
}

int main() {
    struct Node* top = NULL; // Initialize the stack as empty (top points to NULL)

    // Push some elements onto the stack
    top = push(top, 78);  // Push 78 onto the stack
    top = push(top, 70);  // Push 70 onto the stack
    top = push(top, 38);  // Push 38 onto the stack
    top = push(top, 458); // Push 458 onto the stack

    // Print the stack before popping
    printf("Stack before popping:\n");
    lltraversal(top);  // Traverse and print the stack

    // Pop an element from the stack
    int element = pop(&top);  // Pop the top element and update the top pointer
    printf("Popped element: %d\n", element);  // Print the popped element

    // Print the stack after popping
    printf("Stack after popping:\n");
    lltraversal(top);  // Traverse and print the updated stack

    return 0;
}
