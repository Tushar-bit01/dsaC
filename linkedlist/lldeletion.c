#include<stdio.h>
#include<stdlib.h>

// Definition of the linked list node structure
struct Node{
    int data;
    struct Node* next;
};

// Function to traverse and print the linked list
struct Node* lltraversal(struct Node* ptr){
    while(ptr != NULL) {  // Traverse through the list until the end
        printf("%d\n", ptr->data);  // Print the data of the current node
        ptr = ptr->next;  // Move to the next node
    }
}

// Function to delete the first node of the linked list
struct Node* llfirstdelete(struct Node* head){
    struct Node* ptr = head;  // Store the current head
    head = head->next;  // Update head to the next node
    free(ptr);  // Free the memory of the first node
    return head;  // Return the updated head
}

// Function to delete a node at a specific index in the linked list
struct Node* llindexdelete(struct Node* head, int index){
    struct Node* p = head;  // Pointer to traverse the list
    struct Node* q = p->next;  // Pointer to the node to be deleted
    for(int i = 0; i < index - 1; i++){  // Traverse to the node just before the one to be deleted
        p = p->next;
        q = q->next;
    }
    p->next = q->next;  // Bypass the node to be deleted
    free(q);  // Free the memory of the deleted node
    return head;  // Return the updated head
}

// Function to delete the last node of the linked list
struct Node* lllastdelete(struct Node* head){
    struct Node* p = head;  // Pointer to traverse the list
    struct Node* q = p->next;  // Pointer to the last node
    while(q->next != NULL){  // Traverse until the second last node
        p = p->next;
        q = q->next;
    }
    p->next = NULL;  // Set the second last node's next pointer to NULL
    free(q);  // Free the memory of the last node
    return head;  // Return the updated head
}

// Function to delete a node by its value in the linked list
struct Node* llvaluedelete(struct Node* head, int value){
    struct Node* p = head;  // Pointer to traverse the list
    struct Node* q = p->next;  // Pointer to the node to be deleted
    while(q->data != value && q->next != NULL){  // Traverse until the node with the specified value is found
        p = p->next;
        q = q->next;
    }
    if(q->data == value){  // If the node with the specified value is found
        p->next = q->next;  // Bypass the node to be deleted
        free(q);  // Free the memory of the deleted node
    }
    return head;  // Return the updated head
}

int main(){
    // Declare and allocate memory for the nodes
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign data and link the nodes
    head->data = 4;
    head->next = second;
    
    second->data = 3;
    second->next = third;
    
    third->data = 8;
    third->next = fourth;
    
    fourth->data = 1;
    fourth->next = NULL;
    
    printf("Before deleting element:\n");
    lltraversal(head);  // Print the list before any deletions
    
    // Uncomment one of the following delete operations as needed:
    // head = llfirstdelete(head);  // Delete the first node
    // head = llindexdelete(head, 2);  // Delete the node at index 2
    // head = lllastdelete(head);  // Delete the last node
    head = llvaluedelete(head, 8);  // Delete the node with the value 8
    
    printf("After deleting element:\n");
    lltraversal(head);  // Print the list after deletion
}
