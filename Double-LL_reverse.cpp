#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Insert at the beginning of the doubly linked list
void insertAtBegining(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = (*head);

    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode; 
}

// Print the list in forward direction
void printForward(Node* node) {
    cout << "Forward traversal: ";
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

// Reverse the doubly linked list
void reverseList(Node** head) {
    Node* current = *head;
    Node* temp = NULL;

    // Traverse through the list and swap next and prev for each node
    while (current != NULL) {
        // Swap the next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;


        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() 
{
    Node* head = NULL;
    insertAtBegining(&head, 10);
    insertAtBegining(&head, 20);
    insertAtBegining(&head, 30);
    printForward(head);

    reverseList(&head);

    printForward(head);

    return 0;
}
