//
//  BinHeap.h
//

#ifndef _BINHEAP_H_
#define _BINHEAP_H_

#include <iostream>
#include <sstream>

template <class T>
class BinHeap
{
public:
    /* **************************************************************** */
    // Fields
    /* **************************************************************** */
    T* heapArray;
    int maxSize;
    int heapSize;
    
    /* **************************************************************** */
    // EXAM #4 Methods
    /* **************************************************************** */
    bool isMinHeap(int arr[], int numElements);
    T remove(int idx);
    
    /* **************************************************************** */
    // Other Methods
    /* **************************************************************** */
    BinHeap();
    ~BinHeap();
    // Public interface
    bool isEmpty();
    void printHeapToStream(std::stringstream& ss);
    // Private methods
    int leftChildIndex(int idx);
    int rightChildIndex(int idx);
    int parentIndex(int idx);
    int minChild(int idx);
    void percolateUp(int idx);
    void percolateDown(int idx);
    /* **************************************************************** */
};

#endif
