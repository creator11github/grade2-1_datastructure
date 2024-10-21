#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template<class T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T data;
        Node *prev;
        Node *next;
    };

    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedList(); // constructor
    ~DoublyLinkedList(); // destructor

    int getSize() const; // get the number of elements
    bool isEmpty() const; // check whether the container is empty

    void addHead(const T& newData); // add a node at the head
    void addTail(const T& newData); // add a node at the tail

    class Iterator
    {
        friend class DoublyLinkedList<T>;
    private:
        Node *curr;

        Iterator(Node *ptr); // constructor with Node parameter

    public:
        Iterator(); // default constructor

        Iterator operator++(int); // post-increment
        Iterator operator--(int); // post-decrement

        T& operator*() const;

        bool operator==(const Iterator other) const;
        bool operator!=(const Iterator other) const;
    };

    Iterator Begin() const;
    Iterator End() const;
    Iterator rBegin() const; // reverse begin
    Iterator rEnd() const; // reverse end
};

#include "DoublyLinkedList.cpp"

#endif