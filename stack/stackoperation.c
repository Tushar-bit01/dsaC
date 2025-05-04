#include<stdio.h>
#include<stdlib.h>

// Define the stack structure
struct stack {
    int size;   // Maximum number of elements the stack can hold
    int top;    // Index of the top element in the stack (initialized to -1 when empty)
    int *arr;   // Pointer to the dynamically allocated array representing the stack
};

// Function to check if the stack is full
int isfull(struct stack* ptr) {
    if(ptr->top == ptr->size - 1) {  // If top is at size - 1, the stack is full
        return 1;                     // Return 1 (true) if the stack is full
    }
    else {
        return 0;                     // Return 0 (false) if the stack is not full
    }
}

// Function to check if the stack is empty
int isempty(struct stack* ptr) {
    if(ptr->top == -1) {  // If top is -1, the stack is empty
        return 1;          // Return 1 (true) if the stack is empty
    }
    else {
        return 0;          // Return 0 (false) if the stack is not empty
    }
}

// Function to push a value onto the stack
int push(struct stack *ptr, int val) {
    if(isfull(ptr)) {  // Check if the stack is full
        printf("Overflow in stack\n");  // Print error message if the stack is full
    }
    else {
        ptr->top++;                        // Increment the top pointer
        ptr->arr[ptr->top] = val;          // Place the value at the top of the stack
    }
}

// Function to pop a value from the stack
int pop(struct stack *ptr) {
    if(isempty(ptr)) {  // Check if the stack is empty
        printf("Underflow in stack\n");   // Print error message if the stack is empty
        return -1;  // Return a value indicating error, as we can't pop from an empty stack
    }
    else {
        int val = ptr->arr[ptr->top];    // Get the value at the top of the stack
        ptr->top--;                       // Decrement the top pointer to remove the value
        return val;                       // Return the popped value
    }
}

int main() {
    // Dynamically allocate memory for the stack
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    
    // Initialize the stack
    s->top = -1;  // Indicating the stack is empty
    s->size = 10; // Set the stack size
    s->arr = (int*)malloc(s->size * sizeof(int));  // Allocate memory for the stack array
    
    // Print success message for stack creation
    printf("Stack has been created successfully\n");
    
    // Check if the stack is full or empty
    printf("%d\n", isfull(s));  // Print 0 because the stack is empty initially
    printf("%d\n", isempty(s)); // Print 1 because the stack is empty initially
    
    // Push values onto the stack
    push(s, 23);
    push(s, 23);
    push(s, 23);
    push(s, 23);
    push(s, 23);
    push(s, 23);
    push(s, 23);
    push(s, 23);
    push(s, 23);
    push(s, 93);  // This should cause overflow since the stack size is 10
    push(s, 53);  // This also will cause overflow
    
    // Check if the stack is full or empty after pushing values
    printf("%d\n", isfull(s));  // Print 1 because the stack is now full
    printf("%d\n", isempty(s)); // Print 0 because the stack is not empty
    
    // Pop a value from the stack and print it
    printf("%d\n", pop(s));  // Pop and print the top value from the stack
    
    return 0;
}
