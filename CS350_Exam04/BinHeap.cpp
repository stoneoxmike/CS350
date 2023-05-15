//
//  BinHeap.cpp
//

#include "BinHeap.h"
#include "Flags.h"



/* **************************************************************** */

#if ALL || ISMINHEAP
template<class T>
bool BinHeap<T>::isMinHeap(int arr[], int numElements)
{

    // TODO: This method is stubbed out, but does not return the
    // correct value.  Implement this method correctly.
    for (int i = numElements; i > 0; i--) {
        //
        if (arr[i/2] >= arr[i]) {
            return false;
        }
    }

    return true;
    
}
#endif

/* **************************************************************** */

#if ALL || REMOVE
template<class T>
T BinHeap<T>::remove(int idx)
{
    // TODO: This method is stubbed out, but does not return the
    // correct value.  Implement this method correctly.
    T value = -1;
    if (idx <= heapSize && idx > 0) {
        value = heapArray[idx];
        heapArray[idx] = heapArray[heapSize];
        heapSize--;
        percolateDown(idx);
    }
    return value;
    
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* **************************************************************** */
/* **************************************************************** */

// DO NOT DELETE ANYTHING BELOW THIS LINE!!!
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

template class BinHeap<int>;
