//
//  Queue.cpp
//

#include "Queue.h"
#include "Flags.h"


/* **************************************************************** */

#if ALL || CONSTRUCTOR
template<class T>
Queue<T>::Queue()
{
    // TODO: initialize fields so that queue is empty
    // 5 Points
    head = nullptr;
    tail = nullptr;
}
#endif

/* **************************************************************** */

#if ALL || DESTRUCTOR
template<class T>
Queue<T>::~Queue()
{
    // TODO: delete list nodes
    // 5 Points
    makeEmpty();
}
#endif

/* **************************************************************** */

#if ALL || ENQUEUE
template<class T>
void Queue<T>::enqueue(T data)
{
    // TODO: enqueue data
    // 5 Points
    Node<T> *node = new Node<T>();
    node->data = data;
    if (isEmpty()) {
        tail = node;
        head = node;
        node->next = nullptr;
    } else {
        tail->next = node;
        node->next = nullptr;
        tail = node;
    }
}
#endif

/* **************************************************************** */

#if ALL || DEQUEUE
template<class T>
T Queue<T>::dequeue()
{
    // TODO: dequeue data
    // 5 Points

    T val = head->data;
    if (tail == head) {
        delete head;
        tail = nullptr;
        head = nullptr;
    } else {
        Node<T> *nextNode = head->next;
        delete head;
        head = nextNode;
    }
    return val;
    // This method is stubbed out, but does not return the
    // correct value.  Implement this method correctly.
    return -1;
}
#endif

/* **************************************************************** */

#if ALL || ISEMPTY
template<class T>
bool Queue<T>::isEmpty() const
{
    // TODO: return true if the list is empty, false otherwise
    // 5 Points
    return head == nullptr && tail == nullptr;
    // This method is stubbed out, but does not return the
    // correct value.  Implement this method correctly.
    return false;
}
#endif

/* **************************************************************** */

#if ALL || MAKEEMPTY
template<class T>
void Queue<T>::makeEmpty()
{
    // TODO: remove all data values from the queue
    // 5 Points
    while(tail != head) {
        Node<T> *nextNode = head->next;
        delete head;
        head = nextNode;
    }
    delete tail;
    tail = nullptr;
    head = nullptr;
}
#endif

/* **************************************************************** */

// DO NOT DELETE THE FOLLOWING LINE!!!
template class Queue<int>;
