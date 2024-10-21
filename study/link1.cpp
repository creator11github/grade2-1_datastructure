// 链表：在头部插入一个节点
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

void Insert(Node** pointerToHead, int x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (*pointerToHead != NULL)
        temp->next = *pointerToHead;
    *pointerToHead = temp;
}

void Print(Node* head)
{
    cout << "List is: ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    cout << "How many numbers?" << endl;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number" << endl;
        cin >> x;
        Insert(&head, x);
        Print(head);
    }
}