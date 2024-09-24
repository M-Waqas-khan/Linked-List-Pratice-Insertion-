#include <iostream>
using namespace std;
//define the structure for node
struct Node
{
    int data;     //data to store
    Node* next;   //pointer to the next node
};
//Function to insert the node at beginning
void insertAtEnd(Node** head, int newData)
{
    //Alloctae memory for new node
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    //if the list is empty, the new node become the head
    if(*head == NULL)
    {
       *head= newNode;
       return;
    }
    // otherwise find last node
    Node* last = *head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    //link the new node at the End of the List
    last->next = newNode;
}
//function to print the linked list
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
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 55);
    insertAtEnd(&head, 100);
    insertAtEnd(&head, 65);
    insertAtEnd(&head, 79);
    //Print the linked List
    cout<<" Linked List: ";
    printList(head);
    return 0;
}