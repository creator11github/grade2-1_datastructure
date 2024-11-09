#ifndef LIST_H
#define LIST_H

template <typename T>
class list {
private:
    // Define the node structure
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value = T(), Node* p = nullptr, Node* n = nullptr)
            : data(value), prev(p), next(n) {}
    };

    Node* head; // Head pointer
    Node* tail; // Tail pointer
    unsigned list_size; // Size of the list

public:
    // Inner iterator class
    class iterator {
    private:
        Node* current;

    public:
        iterator(Node* node = nullptr) : current(node) {}

        // 21.
        //Precondition: this iterator is positioned at an item in this list.
        //Postcondition: a reference to the item this iterator is positioned at has been returned.
        T& operator*() {
            return current->data;
        }

        // 17.
        //Postcondition: this iterator is now positioned at the next position in this list,
        //and a reference to this iterator has been returned.
        iterator& operator++() {
            current = current->next;
            return *this;
        }

        // 18.
        //Postcondition: this iterator is now positioned at the next position in this list,
        //and a copy of this iterator’s previous value has been returned.
        iterator operator++(int) {
            iterator old = *this;
            current = current->next;
            return old;
        }

        // 19.
        //Postcondition: this iterator is now positioned at the previous position in this list,
        //and a reference to this iterator has been returned.
        iterator& operator--() {
            current = current->prev;
            return *this;
        }

        // 20.
        //Postcondition: this iterator is now positioned at the previous position in this list,
        //and a copy of this iterator’s previous value has been returned.
        iterator operator--(int) {
            iterator old = *this;
            current = current->prev;
            return old;
        }

        // 22.
        //Postcondition: true has been returned if this iterator is positioned at the same place
        //in this list x is positioned at. Otherwise, false has been returned.
        bool operator==(const iterator& x) const {
            return current == x.current;
        }

        bool operator!=(const iterator& x) const {
            return current != x.current;
        }

        Node* getNode() const {
            return current;
        }
    };

    // 1.
    //Postcondition: this list is empty
    list() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        list_size = 0;
    }

    // 3.
    //copy constructor
    //Postcondition: this list has been constructed and initialized to a copy of x
    //The worstTime(n) is O(n), where n is the size of x.
    list(const list<T>& x) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        list_size = 0;
        for (Node* p = x.head->next; p != x.tail; p = p->next) {
            push_back(p->data);
        }
    }

    // 15.
    //copy assignment: Replaces the contents with a copy of the contents of x.
    //Postcondition: this list contains a copy of x,
    //and a reference to this list has been returned
    list<T>& operator=(const list<T>& x) {
        if (this != &x) {
            clear();
            for (Node* p = x.head->next; p != x.tail; p = p->next) {
                push_back(p->data);
            }
        }
        return *this;
    }

    // 2.
    //Postcondition: this list has been destroyed
    ~list() {
        clear();
        delete head;
        delete tail;
    }

    // 4.
    //Postcondition: x has been inserted at the front of this list.
    void push_front(const T& x) {
        insert(begin(), x);
    }

    // 5.
    //Postcondition: x has been inserted at the back of this list.
    void push_back(const T& x) {
        insert(end(), x);
    }

    // 6.
    //Postcondition: x has been inserted in this list in front of the item that position was
    //positioned at before this call. An iterator positioned at x has been returned.
    iterator insert(iterator position, const T& x) {
        Node* posNode = position.getNode();
        Node* newNode = new Node(x, posNode->prev, posNode);
        posNode->prev->next = newNode;
        posNode->prev = newNode;
        ++list_size;
        return iterator(newNode);
    }

    // 7.
    //Precondition: this list is not empty
    //Postcondition: the item that was at the front of this list before this call was made
    //has been deleted from this list.
    void pop_front() {
        if (!empty()) {
            erase(begin());
        }
    }

    // 8.
    //Precondition: this list is not empty
    //Postcondition: the item that was at the back of this list before this call was made
    //has been deleted from this list.
    void pop_back() {
        if (!empty()) {
            iterator temp = end();
            temp--;
            erase(temp);
        }
    }

    // 9.
    //Precondition: position is positioned at an item in this list
    //Postcondition: the item that position was positioned at before this call was made
    //has been deleted from this list
    //return value: An iterator pointing to the element that followed the element
    //erased by the function call.
    iterator erase(iterator position) {
        Node* posNode = position.getNode();
        Node* prevNode = posNode->prev;
        Node* nextNode = posNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete posNode;
        --list_size;
        return iterator(nextNode);
    }

    // 10.
    //Precondition: first is positioned at some item in this list, and last is positioned one past
    //some item in this list.
    //Postcondition: all the items that, before this call was made, were in the range from first
    //(inclusive) to last (exclusive) have been deleted from this list
    //that is, remove the elements in the range [first, last).
    //return: Iterator following the last removed element.
    iterator erase(iterator first, iterator last) {
        while (first != last) {
            first = erase(first);
        }
        return last;
    }

    // 11.
    //Postcondition: the number of items in this list has been returned.
    unsigned size() const {
        return list_size;
    }

    // 12.
    //Postcondition: true has been returned if this list is empty; Otherwise, false has been returned.
    bool empty() const {
        return list_size == 0;
    }

    // 13.
    //Postcondition: an iterator positioned at the front of this list has been returned
    //If the list is empty, the returned iterator will be equal to end(). (See 14.)
    iterator begin() {
        return iterator(head->next);
    }

    // 14.
    //Postcondition: an iterator positioned AFTER the last item in this list has been returned.
    iterator end() {
        return iterator(tail);
    }

    // 16.
    //Postcondition: The contents of x have been inserted, starting at position (in front of position),
    //into this list, and x is empty
    void splice(iterator position, list<T>& x) {
        if (!x.empty()) {
            Node* posNode = position.getNode();
            Node* x_first = x.head->next;
            Node* x_last = x.tail->prev;

            // Adjust x's nodes
            x.head->next = x.tail;
            x.tail->prev = x.head;

            // Adjust current list's nodes
            x_first->prev = posNode->prev;
            x_last->next = posNode;
            posNode->prev->next = x_first;
            posNode->prev = x_last;

            list_size += x.list_size;
            x.list_size = 0;
        }
    }

private:
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }
};

#endif // LIST_H