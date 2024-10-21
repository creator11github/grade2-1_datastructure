// 链表：任意位置删除节点
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* head;

void Insert(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node* temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}
void Print()
{
    Node* temp = head;
    cout << "List is: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void Delete(int n)
{
    Node* temp1 = head;
    if (n == 1)
    {
        head = temp1->next; // head now points to second Node
        delete temp1;       // delete first Node
        return;
    }
    for (int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next; // temp1 points to (n-1)th Node
    }
    Node* temp2 = temp1->next; // nth Node
    temp1->next = temp2->next; // (n+1)th Node
    delete temp2;              // delete nth Node
}

int main()
{
    head = NULL; // empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); // List: 2, 4, 6, 5
    int n;
    cout << "Enter a position: ";
    cin >> n;
    Delete(n);
    Print();
}