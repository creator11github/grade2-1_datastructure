//链表：双向链表
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};
Node* head;

Node* GetNewNode(int x)
{
    Node* newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int x)
{
    Node* newNode = GetNewNode(x);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(int x)
{
    Node* temp = head;
    Node* newNode = GetNewNode(x);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    while(temp->next != NULL)
    {
        temp = temp->next; // Go To last Node
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void Print()
{
    Node* temp = head;
    cout << "List is: ";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void ReversePrint()
{
    Node* temp = head;
    if(temp == NULL) return;// empty list, exit
    // Going to last Node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    // Traversing backward using prev pointer
    cout << "Reverse List is: ";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    head = NULL; // empty list
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(6); Print(); ReversePrint();
}