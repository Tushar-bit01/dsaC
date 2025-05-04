#include<stdio.h>
#include<stdlib.h>

// Define a stack structure
struct stack{
    int top;        // Index of the top element in the stack
    int size;       // Maximum number of elements the stack can hold
    int* arr;       // Pointer to the array representing the stack
};

// Function to check if the stack is empty
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){   // If top is -1, the stack is empty
        return 1;          // Return 1 (true) indicating the stack is empty
    }
    else{
        return 0;          // Return 0 (false) if the stack is not empty
    }
}

// Function to check if the stack is full
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){   // If top is equal to size-1, the stack is full
        return 1;                    // Return 1 (true) indicating the stack is full
    }
    else{
        return 0;                    // Return 0 (false) if the stack is not full
    }
}

int main(){
    // Dynamically allocate memory for the stack
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    
    // Set the size of the stack and initialize top to -1 (indicating an empty stack)
    s->size = 10;
    s->top = -1;

    // Dynamically allocate memory for the stack's array to hold integers
    s->arr = (int*)malloc(s->size * sizeof(int));

    // Check if the stack is empty using the isEmpty function
    if(isEmpty(s)){
        printf("stack is empty\n");    // Print message if the stack is empty
    }
    else{
        printf("The stack is not empty\n");  // Print message if the stack is not empty
    }

    return 0;
}
