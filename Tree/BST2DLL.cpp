#include <iostream> 
using namespace std; 
  
struct node 
{ 
    int data; 
    node* left; 
    node* right; 
}; 
  
// A simple recursive function to convert a given Binary tree to Doubly 
// Linked List 
// root --> Root of Binary Tree 
// head --> Pointer to head node of created doubly linked list 
void BinaryTree2DoubleLinkedList(node *root, node **head) 
{ 
    // Base case 
    if (root == NULL) return; 
  
    // Initialize previously visited node as NULL. This is 
    // static so that the same value is accessible in all recursive 
    // calls 
    static node* prev = NULL; 
  
    BinaryTree2DoubleLinkedList(root->left, head); 
  
    if (prev == NULL) 
        *head = root; 
    else
    { 
        root->left = prev; 
        prev->right = root; 
    } 
    prev = root; 
  
    BinaryTree2DoubleLinkedList(root->right, head); 
} 
  
node* newNode(int data) 
{ 
    node* new_node = new node; 
    new_node->data = data; 
    new_node->left = new_node->right = NULL; 
    return (new_node); 
} 
  
void printList(node *node) 
{ 
    while (node!=NULL) 
    { 
        cout << node->data << " "; 
        node = node->right; 
    } 
} 
  
int main() 
{ 
    node *root        = newNode(10); 
    root->left        = newNode(12); 
    root->right       = newNode(15); 
    root->left->left  = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36); 
   
    node *head = NULL; 
    BinaryTree2DoubleLinkedList(root, &head); 
  
    printList(head); 
  
    return 0; 
} 