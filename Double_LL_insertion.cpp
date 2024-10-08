#include <iostream>
using namespace std;
struct Node
{
 int data;
 Node* prev;
 Node* next;
};
void insertAtBegining(Node** head, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = (*head);
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode; 
}
void printForward(Node* node)
{
    cout<<" Forward traversal: ";
    while(node != NULL)
    {
        cout<<node->data<<" -> ";
        node = node->next;
    }
    cout<< "NULL" <<endl;
}
int main()
{
    Node* head = NULL;
    insertAtBegining(&head, 10);
    insertAtBegining(&head, 20);
    insertAtBegining(&head, 10);

    printForward(head);
}