#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// Function to traverse and print the elements of the circular linked list
void lltraversal(struct Node* head) {
    if (head == NULL) {
        return;  // If the list is empty, do nothing
    }

    struct Node* ptr = head;
    do {
        printf("%d\n", ptr->data);  // Print the data of the node
        ptr = ptr->next;  // Move to the next node
    } while(ptr != head);  // Stop when we reach the head node again (circular list)
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

    // Link the third node back to the first node to form a circular linked list
    third->data = 69;
    third->next = head;

    // Traverse and print the circular linked list
    lltraversal(head);

    // Free the memory of the nodes in the linked list
    struct Node* temp;
    // Since it's circular, we need to break the loop before freeing the nodes
    do {
        temp = head;
        head = head->next;
        free(temp);
    } while(head != NULL);

    return 0;
}
