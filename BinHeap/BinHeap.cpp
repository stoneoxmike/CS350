//
//  BinHeap.cpp
//

#include "BinHeap.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
template <class T>
BinHeap<T>::BinHeap()
{
    // TODO: Allocate initial heap array and store sentinel value
    heapArray = new T[2];
    heapArray[0] = -1;
    heapSize = 0;
    maxSize = 1;
}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
template <class T>
BinHeap<T>::~BinHeap()
{
    // TODO: Deallocate heap array
    delete[] heapArray;
}
#endif

/* **************************************************************** */

#if ISEMPTY || ALL
// TODO: isEmpty() method
template <class T>
bool BinHeap<T>::isEmpty() {
    return heapSize == 0;
}
#endif

/* **************************************************************** */

#if MAKEEMPTY || ALL
// TODO: makeEmpty() method
template <class T>
void BinHeap<T>::makeEmpty() {
    delete[] heapArray;
    heapArray = new T[2];
    heapArray[0] = -1;
    heapSize = 0;
    maxSize = 1;
}
#endif

/* **************************************************************** */

#if RESIZEARRAY || ALL
// TODO: resizeArray() method
template <class T>
void BinHeap<T>::resizeArray(int newSize) {
    T* newArr = new T[newSize];
    for (int i = 0; i <= heapSize; i++) {
        newArr[i] = heapArray[i];
    }
    delete[] heapArray;
    heapArray = newArr;
    maxSize = newSize;
}
#endif

/* **************************************************************** */

#if LEFTCHILDINDEX || ALL
// TODO: leftChildIndex() method
template <class T>
int BinHeap<T>::leftChildIndex(int idx) {
    return 2*idx;
}
#endif

/* **************************************************************** */

#if RIGHTCHILDINDEX || ALL
// TODO: rightChildIndex() method
template <class T>
int BinHeap<T>::rightChildIndex(int idx) {
    return 2*idx + 1;
}
#endif

/* **************************************************************** */

#if PARENTINDEX || ALL
// TODO: parentIndex() method
template <class T>
int BinHeap<T>::parentIndex(int idx) {
    return idx/2;
}
#endif

/* **************************************************************** */

#if MINCHILD || ALL
// TODO: minChild() method
template <class T>
int BinHeap<T>::minChild(int idx) {
    int leftChild = leftChildIndex(idx);
    int rightChild = rightChildIndex(idx);
    if (leftChild <= heapSize && rightChild <= heapSize) {
        return heapArray[leftChild] > heapArray[rightChild] ? rightChild : leftChild;
    } else if (leftChild == heapSize) {
        return leftChild;
    }
    return -1;
}
#endif

/* **************************************************************** */

#if INSERT || ALL
// TODO: insert() method
template <class T>
void BinHeap<T>::insert(const T &x) {
    if (heapSize == maxSize) {
        resizeArray(maxSize * 2);
    }
    heapSize++;
    heapArray[heapSize] = x;
    percolateUp(heapSize);
}
#endif

/* **************************************************************** */

#if REMOVEMIN || ALL
// TODO: removeMin() method
template <class T>
T BinHeap<T>::removeMin() {
    if (!isEmpty()) {
        T min = heapArray[1];
        heapArray[1] = heapArray[heapSize];
        percolateDown(1);
        heapSize--;
        if (heapSize < maxSize/3.0) {
            resizeArray(maxSize/2);
        }
        return min;
    }
    return -1;
}
#endif

/* **************************************************************** */

#if PERCOLATEUP || ALL
// TODO: percolateUp() method
template <class T>
void BinHeap<T>::percolateUp(int idx) {
    int parIdx = parentIndex(idx);
    if (heapArray[parIdx] > heapArray[idx] && parIdx > 0) {
        T temp = heapArray[parIdx];
        heapArray[parIdx] = heapArray[idx];
        heapArray[idx] = temp;
        percolateUp(parIdx);
    }
}
#endif

/* **************************************************************** */

#if PERCOLATEDOWN || ALL
// TODO: percolateDown() method
template <class T>
void BinHeap<T>::percolateDown(int idx) {
    int childIdx = minChild(idx);
    if (heapArray[idx] > heapArray[childIdx] && childIdx >= 0) {
        T temp = heapArray[idx];
        heapArray[idx] = heapArray[childIdx];
        heapArray[childIdx] = temp;
        percolateDown(childIdx);
    }
}
#endif

/* **************************************************************** */

#if BUILDHEAP || ALL
// TODO: buildHeap() method
template <class T>
void BinHeap<T>::buildHeap(const T *arr, int size) {
    resizeArray(size);
    heapSize = size;
    for (int i = 1; i <= size; i++) {
        heapArray[i] = arr[i-1];
    }
    for (int i = heapSize/2; i >= 1; i--) {
        percolateDown(i);
    }
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
template <class T>
void BinHeap<T>::printHeap()
{
    std::stringstream ss;
    printHeapToStream(ss);
    std::cout << ss.str();
}


template <class T>
void BinHeap<T>::printHeapToStream(std::stringstream& ss)
{
    ss << "  Current array size: " << maxSize << std::endl;
    ss << "  Current heap size: " << heapSize << std::endl;
    
    if (!isEmpty()) {
        ss << "  Heap Elements: ";
        // Print heap array
        for (int i = 1; i <= heapSize; i++) {
            ss << heapArray[i] << " ";
        }
    }
    else {
        ss << "  Heap is empty";
    }
    ss << std::endl << std::endl;
}
#endif

template class BinHeap<int>;
