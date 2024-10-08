#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Insert at the end of the doubly linked list
void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node();  // Create new node
    newNode->data = newData;     // Assign data to the new node
    newNode->next = NULL;        // Since it's the last node, next is NULL
    
    // If the list is empty, make the new node the head
    if (*head == NULL) {
        newNode->prev = NULL;  // No previous node as this is the only node
        *head = newNode;
        return;
    }

    // Traverse to the last node
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node to point to the new node
    last->next = newNode;
    newNode->prev = last;  // Set the new node's previous to the last node
}

// Print the list in forward direction
void printForward(Node* node) {
    cout << "End traversal: ";
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() 
{
    Node* head = NULL;

    // Insert values at the end of the list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Print the list in forward order
    printForward(head);

    return 0;
}
