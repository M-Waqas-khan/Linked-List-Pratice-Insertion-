#include <iostream>
using namespace std;
//define the structure for node
struct Node
{
    int data;     //data to store
    Node* next;   //pointer to the next node
};
//Function to insert the node at beginning
void insertAtBeginning(Node** head, int newData)
{
    //Alloctae memory for new node
    Node* newNode = new Node();
    //Assign data to the new node
    newNode->data = newData;
    //make next of new node point to the current head
    newNode->next = *head;
    //Move the head to point to the new node
    *head = newNode;
}
void printList(Node* node)
{
    while(node != nullptr)
    {
      cout<<node->data<<"->";
      node = node->next;
    }
    cout<<" Null "<<endl;
}
int main()
{
    cout<<"\n\n************Lab 5 linked list Implementation************\n\n"<<endl;
    //initialize the head as Null(empty list)
    Node* head = nullptr;
    //insert NOde in Beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    //Print the linked List
    cout<<" Linked List: ";
    printList(head);
    return 0;
}