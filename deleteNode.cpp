#include <iostream>
using namespace std;
struct Node
{
    int data;     //data to store
    Node* next;   //pointer to the next node
};
void insertAtEnd(Node** head, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    if(*head == NULL)
    {
       *head= newNode;
       return;
    }
    Node* last = *head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    //link the new node at the End of the List
    last->next = newNode;
}
void deleteNode(Node** head,int key)
{
    Node* temp = *head;
    Node* prev = NULL;
    //if head node holds the key to be deleted
    if(temp != NULL && temp->data == key)
    {
       *head = temp->next;
       delete temp; 
       return;   
    }
    // Search the key to be deleted
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
      cout<<" Value not found in the List. ";
    }
    // unlink the node from list
    prev->next =  temp->next;
    //free memory of Node
    delete temp;
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
    //initialize the head as Null(empty list)
    Node* head = NULL;
    int value,newData,deleteValue;
    cout<<" How many values you want tho Enter: ";
    cin>>value;
    for(int i=0; i<value; i++)
    {
        cout<<" The value "<<i<<" is: ";
        cin>>newData;
        //insert NOde in Beginning
        insertAtEnd(&head, newData);
    }
    // print the linked list
    cout<<" The linked list is: ";
    printList(head);
    //Ask the user for the value to delete
    cout<<" Enter the value of the node to be deleted: ";
    cin>>deleteValue;
    // delete the node with the specified
    deleteNode(&head , deleteValue);
    //print the linked list after deletion
    cout<<" The linked list After deletion is: ";
    printList(head);
    return 0;
}