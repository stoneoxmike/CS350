//
//  IntArrayStack.cpp
//

#include "IntArrayStack.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
// TODO: Constructor
IntArrayStack::IntArrayStack() {
    capacity = 1;
    stack = new int[capacity];
    top = -1;
}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
// TODO: Destructor
IntArrayStack::~IntArrayStack() {
    delete[] stack;
}
#endif

/* **************************************************************** */

#if PUSH || ALL
// TODO: push()
void IntArrayStack::push(int x) {
    if (top+1 == capacity) {
        resize(capacity*2);
    }
    stack[++top] = x;
}
#endif

/* **************************************************************** */

#if POP || ALL
// TODO: pop()
int IntArrayStack::pop() {
    if (!isEmpty()) {
        int val = stack[top--];
        if ((((top + 1.0)/capacity) < (1.0/3.0)) && capacity > 1) {
            resize(capacity/2);
        }
        return val;
    } else {
        return -1;
    }
}
#endif

/* **************************************************************** */

#if PEEK || ALL
// TODO: peek()
int IntArrayStack::peek() {
    if (!isEmpty()) {
        return stack[top];
    } else {
        return -1;
    }
}
#endif

/* **************************************************************** */

#if ISEMPTY || ALL
// TODO: isEmpty()
bool IntArrayStack::isEmpty() {
    return top == -1;
}
#endif

/* **************************************************************** */

#if EMPTYSTACK || ALL
// TODO: emptyStack()
void IntArrayStack::emptyStack() {
    top = -1;
    resize(1);
}
#endif

/* **************************************************************** */

#if RESIZE || ALL
// TODO: resize()
void IntArrayStack::resize(int newCapacity) {
    int *temp = new int[newCapacity];
    for (int a = 0; a <= top; a++) {
        temp[a] = stack[a];
    }
    delete[] stack;
    stack = temp;
    capacity = newCapacity;
}
#endif

/* **************************************************************** */
// Do NOT modify anything below this line
// Do NOT use these methods in your implementation of your data
// structure.  They are included here to support the unit tests.
/* **************************************************************** */

#ifndef BUILD_LIB
void IntArrayStack::printStack()
{
    std::cout << std::endl;
    std::cout << "Current array size: " << capacity << std::endl;
    std::cout << "Number of ints in stack: " << top+1 << std::endl;
    for (int i=top; i >= 0; i--)
    {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}


// Do NOT use this method in your implementation
int IntArrayStack::getCapacity()
{
    return capacity;
}


// Do NOT use this method in your implementation
int IntArrayStack::getSize()
{
    return top+1;
}


// Do NOT use this method in your implementation
int IntArrayStack::getTop()
{
    return top;
}


// Do NOT use this method in your implementation
void IntArrayStack::toArray(int* arr)
{
    for (int i=0; i < capacity; i++)
    {
        arr[i] = stack[i];
    }
}

#endif

/* **************************************************************** */


