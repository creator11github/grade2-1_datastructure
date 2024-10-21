// 链表：递归法反转链表
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* head;

Node* Insert(Node* head, int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node* temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
}

void Print(Node* head)
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

void Reverse(Node *p)
{
    if (p->next == NULL) // 递归终止条件
    {
        head = p;
        return;
    }
    Reverse(p->next);
    Node* q = p->next;
    q->next = p;
    //p->next->next = p;
    p->next = NULL;
}

int main()
{
    head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);
    Print(head);
    Reverse(head);
    Print(head);
}