#include "DoublyLinkedList.h"

template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node *current = head;
    Node *temp;
    while (current != nullptr)
    {
        temp = current;
        current = current->next;
        delete temp;
    }
}

template<class T>
int DoublyLinkedList<T>::getSize() const
{
    return size;
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() const
{
    return size == 0;
}

template<class T>
void DoublyLinkedList<T>::addHead(const T& newData)
{
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr)
    {
        head->prev = newNode;
    }
    head = newNode;

    if (tail == nullptr)
    {
        tail = newNode;
    }

    size++;
}

template<class T>
void DoublyLinkedList<T>::addTail(const T& newData)
{
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr)
    {
        tail->next = newNode;
    }
    tail = newNode;

    if (head == nullptr)
    {
        head = newNode;
    }

    size++;
}

template<class T>
DoublyLinkedList<T>::Iterator::Iterator()
{
    curr = nullptr;
}

template<class T>
DoublyLinkedList<T>::Iterator::Iterator(Node *ptr)
{
    curr = ptr;
}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator++(int)
{
    Iterator temp = *this;
    if (curr != nullptr)
    {
        curr = curr->next;
    }
    return temp;
}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator--(int)
{
    Iterator temp = *this;
    if (curr != nullptr)
    {
        curr = curr->prev;
    }
    return temp;
}

template<class T>
T& DoublyLinkedList<T>::Iterator::operator*() const
{
    return curr->data;
}

template<class T>
bool DoublyLinkedList<T>::Iterator::operator==(const Iterator other) const
{
    return curr == other.curr;
}

template<class T>
bool DoublyLinkedList<T>::Iterator::operator!=(const Iterator other) const
{
    return curr != other.curr;
}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Begin() const
{
    return Iterator(head);
}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::End() const
{
    return Iterator();
}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::rBegin() const
{
    return Iterator(tail);
}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::rEnd() const
{
    return Iterator();
}