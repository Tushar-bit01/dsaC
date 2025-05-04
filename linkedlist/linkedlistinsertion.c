#include<stdio.h>
#include<stdlib.h>

// Define a structure for the linked list node
struct Node{
    int data;
    struct Node* next;
};

// Function to traverse and print the linked list
void lltraversal(struct Node* ptr) {
    while(ptr != NULL) {
        printf("%d\n", ptr->data);  // Print each node's data
        ptr = ptr->next;  // Move to the next node
    }
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertionatstrt(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));  // Create a new node
    ptr->data = data;  // Set the data for the new node
    ptr->next = head;  // Link the new node to the current head
    head = ptr;  // Update the head to the new node
    return head;  // Return the new head
}

// Function to insert a new node at a specific index in the linked list
struct Node* insertionatindex(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));  // Create a new node
    struct Node* p = head;  // Start at the head node
    for(int i = 0; i < index - 1; i++) {  // Traverse the list to the node before the desired index
        p = p->next;
    }
    ptr->data = data;  // Set the data for the new node
    ptr->next = p->next;  // Link the new node to the next node of the current node
    p->next = ptr;  // Link the current node to the new node
    return head;  // Return the updated head
}

// Function to insert a new node at the end of the linked list
struct Node* insertatend(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));  // Create a new node
    struct Node* p = head;  // Start at the head node
    while(p->next != NULL) {  // Traverse to the last node
        p = p->next;
    }
    ptr->data = data;  // Set the data for the new node
    p->next = ptr;  // Link the last node to the new node
    ptr->next = NULL;  // Mark the new node as the last node
    return head;  // Return the updated head
}

// Function to insert a new node after a specific node
struct Node* insertionafternode(struct Node* head, struct Node* pnode, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));  // Create a new node
    ptr->data = data;  // Set the data for the new node
    ptr->next = pnode->next;  // Link the new node to the next node of the given node
    pnode->next = ptr;  // Link the given node to the new node
    return head;  // Return the updated head
}

int main() {
    struct Node* head;
    struct Node* second;
    struct Node* third;

    // Allocate memory for the nodes in the linked list
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Link the first and second nodes
    head->data = 7;
    head->next = second;

    // Link the second and third nodes
    second->data = 11;
    second->next = third;

    // Terminate the third node (end of the list)
    third->data = 69;
    third->next = NULL;

    // Print the initial linked list
    lltraversal(head);

    // Insert a node after the second node (using the insertionafternode function)
    head = insertionafternode(head, second, 65);

    // Print the updated linked list after insertion
    lltraversal(head);

    // Free the allocated memory for each node
    struct Node* temp;
    while(head != NULL) {
        temp = head;  // Store the current node
        head = head->next;  // Move to the next node
        free(temp);  // Free the current node's memory
    }

    return 0;
}
