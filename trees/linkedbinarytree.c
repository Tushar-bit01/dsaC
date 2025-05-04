#include <stdio.h>
#include<stdlib.h>

// Define a structure for a binary tree node
struct Node{
    int data;            // Data to store the value of the node
    struct Node* left;   // Pointer to the left child
    struct Node* right;  // Pointer to the right child
};

// Function to create a new node with given data
struct Node* createNode(int data){
    // Dynamically allocate memory for a new node
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    
    // Initialize the data of the node
    n->data = data;
    
    // Set the left and right children to NULL (leaf node)
    n->left = NULL;
    n->right = NULL;

    // Return the created node
    return n;
}   

// Function to perform Preorder traversal (Root, Left, Right)
void preorder(struct Node* root){
    // Check if the node is not NULL
    if(root != NULL){
        // Print the data of the current node
        printf("%d ", root->data);
        
        // Recursively traverse the left subtree
        preorder(root->left);
        
        // Recursively traverse the right subtree
        preorder(root->right);
    }
}

// Function to perform Inorder traversal (Left, Root, Right)
void inorder(struct Node* root){
    // Check if the node is not NULL
    if(root != NULL){
        // Recursively traverse the left subtree
        inorder(root->left);
        
        // Print the data of the current node
        printf("%d ", root->data);
        
        // Recursively traverse the right subtree
        inorder(root->right);
    }
}

// Function to perform Postorder traversal (Left, Right, Root)
void postorder(struct Node* root){
    // Check if the node is not NULL
    if(root != NULL){
        // Recursively traverse the left subtree
        postorder(root->left);
        
        // Recursively traverse the right subtree
        postorder(root->right);
        
        // Print the data of the current node
        printf("%d ", root->data);
    }
}

int main() {
    // Constructing the root node with value 4
    struct Node* p = createNode(4);
    
    // Constructing left child with value 1
    struct Node* p1 = createNode(1);
    
    // Constructing right child with value 6
    struct Node* p2 = createNode(6);
    
    // Constructing left child of node 1 with value 5
    struct Node* p3 = createNode(5);
    
    // Constructing right child of node 1 with value 2
    struct Node* p4 = createNode(2);
    
    // Linking the root node with its left and right children
    p->left = p1;
    p->right = p2;
    
    // Linking the left child of node 1 with its left and right children
    p1->left = p3;
    p1->right = p4;
    
    // Print Preorder traversal of the tree
    printf("\nPreorder Traversal: \n");
    preorder(p);
    
    // Print Inorder traversal of the tree
    printf("\nInorder Traversal: \n");
    inorder(p);
    
    // Print Postorder traversal of the tree
    printf("\nPostorder Traversal: \n");
    postorder(p);
    
    return 0;
}
