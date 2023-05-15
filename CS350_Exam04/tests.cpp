//
//  tests.cpp
//

#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_CONSOLE_WIDTH 120

#include <sstream>
#include <iomanip>
#include <assert.h>
#include "BinHeap.h"
#include "catch.hpp"


/* **************************************************************** */
/* **************************************************************** */

#define UNUSED -1
#define NUM_HEAP_ELEMENTS(arr)  int((sizeof(arr)/sizeof(arr[0])) - 1)


void printArrayContentsToStream(std::stringstream& ss, int arr[], int numElements) {
    ss << "Number of heap elements in array: " << numElements << "\n";
    
    std::string s = "Contents of array to check:  ";
    ss << std::setw(s.length()) << s;
    for (int i = 0; i <= numElements; i++) {
        ss << "| " << std::setw(2) << arr[i] << " ";
    }
    ss << "|\n";
    
    ss << std::setw(s.length()) << "arr index ->  ";
    for (int i = 0; i <= numElements; i++) {
        ss << std::setw(4) << i << " ";
    }
}


void makeHeap(BinHeap<int> & heap, int arr[], int backarrSize, int maxHeapSize) {
    assert(maxHeapSize >= backarrSize);
    delete[] heap.heapArray;
    heap.heapArray = new int[maxHeapSize+1];
    heap.heapArray[0] = -1;
    heap.heapSize = backarrSize;
    heap.maxSize = maxHeapSize;
    
    for (int i = 0; i < backarrSize; i++) {
        heap.heapArray[i+1] = arr[i];
    }
}


void removeTestSetup(BinHeap<int> & heap, std::stringstream & setupInfo) {
    int arr[] = { 2, 4, 6, 15, 12, 18, 8, 17, 16, 20, 14 };
    int arrSize = 11;
    int maxHeapSize = 11;
    makeHeap(heap, arr, arrSize, maxHeapSize);
    setupInfo << "before calling remove(), BinHeap is:\n";
    heap.printHeapToStream(setupInfo);
    INFO(setupInfo.str());
    REQUIRE(heap.maxSize == 11);
    REQUIRE(heap.heapSize == 11);
    REQUIRE(heap.heapArray != nullptr);
    REQUIRE(heap.heapArray[0] == -1);
    REQUIRE(heap.heapArray[1] == 2);
    REQUIRE(heap.heapArray[2] == 4);
    REQUIRE(heap.heapArray[3] == 6);
    REQUIRE(heap.heapArray[4] == 15);
    REQUIRE(heap.heapArray[5] == 12);
    REQUIRE(heap.heapArray[6] == 18);
    REQUIRE(heap.heapArray[7] == 8);
    REQUIRE(heap.heapArray[8] == 17);
    REQUIRE(heap.heapArray[9] == 16);
    REQUIRE(heap.heapArray[10] == 20);
    REQUIRE(heap.heapArray[11] == 14);
}


/* **************************************************************** */
// ISMINHEAP
/* **************************************************************** */


// 1 point
TEST_CASE("verify that isMinHeap(heapArr[],numElements) returns true when BinHeap is empty", "[ISMINHEAP][11]") {
    BinHeap<int> heap;
    int heapArr[] = { UNUSED };
    int numElements = NUM_HEAP_ELEMENTS(heapArr);
    std::stringstream ss;
    printArrayContentsToStream(ss, heapArr, numElements);
    INFO(ss.str());
    REQUIRE(heap.isMinHeap(heapArr, numElements) == true);
}


// 1 point
TEST_CASE("verify that isMinHeap(heapArr[],numElements) returns true when BinHeap has only a single element", "[ISMINHEAP][12]") {
    BinHeap<int> heap;
    int heapArr[] = { UNUSED, 1 };
    int numElements = NUM_HEAP_ELEMENTS(heapArr);
    std::stringstream ss;
    printArrayContentsToStream(ss, heapArr, numElements);
    INFO(ss.str());
    REQUIRE(heap.isMinHeap(heapArr, numElements) == true);
}


// 2 points
TEST_CASE("verify that isMinHeap(heapArr[],numElements) returns true when a valid BinHeap has a full bottom", "[ISMINHEAP][13]") {
    BinHeap<int> heap;
    int heapArr[] = { UNUSED, 1, 7, 9, 15, 16, 21, 10, 25, 30, 18, 19, 22, 35, 11, 40 };
    int numElements = NUM_HEAP_ELEMENTS(heapArr);
    std::stringstream ss;
    printArrayContentsToStream(ss, heapArr, numElements);
    INFO(ss.str());
    REQUIRE(heap.isMinHeap(heapArr, numElements) == true);
}


// 2 points
TEST_CASE("verify that isMinHeap(heapArr[],numElements) returns true when a valid BinHeap has a non-full bottom", "[ISMINHEAP][14]") {
    BinHeap<int> heap;
    int heapArr[] = { UNUSED, 1, 7, 9, 15, 16, 21, 10, 25, 30, 18, 19 };
    int numElements = NUM_HEAP_ELEMENTS(heapArr);
    std::stringstream ss;
    printArrayContentsToStream(ss, heapArr, numElements);
    INFO(ss.str());
    REQUIRE(heap.isMinHeap(heapArr, numElements) == true);
}


// 2 points
TEST_CASE("verify that isMinHeap(heapArr[],numElements) returns true when a valid BinHeap has an element with only a left child", "[ISMINHEAP][15]") {
    BinHeap<int> heap;
    int heapArr[] = { UNUSED, 1, 7, 9, 15, 16, 21, 10, 25, 30, 18, 0 };
    int numElements = NUM_HEAP_ELEMENTS(heapArr) - 1;  //last entry^ is dummy data 
    std::stringstream ss;
    printArrayContentsToStream(ss, heapArr, numElements);
    INFO(ss.str());
    REQUIRE(heap.isMinHeap(heapArr, numElements) == true);
}


// 1 points
TEST_CASE("verify that isMinHeap(heapArr[],numElements) returns false when an element in a BinHeap has a full bottom and an invalid left child", "[ISMINHEAP][16]") {
    BinHeap<int> heap;
    int heapArr[] = { UNUSED, 1, 7, 9, 6, 16, 21, 10, 25, 30, 18, 19, 22, 35, 11, 40 };
    int numElements = NUM_HEAP_ELEMENTS(heapArr);
    std::stringstream ss;
    printArrayContentsToStream(ss, heapArr, numElements);
    INFO(ss.str());
    REQUIRE(heap.isMinHeap(heapArr, numElements) == false);
}


// 1 points
TEST_CASE("verify that isMinHeap(heapArr[],numElements) returns false when an element in a BinHeap has a non-full bottom and an invalid left child", "[ISMINHEAP][17]") {
    BinHeap<int> heap;
    int heapArr[] = { UNUSED, 1, 7, 9, 15, 16, 21, 10, 25, 30, 12, 19 };
    int numElements = NUM_HEAP_ELEMENTS(heapArr);
    std::stringstream ss;
    printArrayContentsToStream(ss, heapArr, numElements);
    INFO(ss.str());
    REQUIRE(heap.isMinHeap(heapArr, numElements) == false);
}


// 1 points
TEST_CASE("verify that isMinHeap(heapArr[],numElements) returns false when an element in a BinHeap has a full bottom and an invalid right child", "[ISMINHEAP][18]") {
    BinHeap<int> heap;
    int heapArr[] = { UNUSED, 1, 7, 9, 15, 6, 21, 10, 25, 30, 18, 19, 22, 35, 11, 40 };
    int numElements = NUM_HEAP_ELEMENTS(heapArr);
    std::stringstream ss;
    printArrayContentsToStream(ss, heapArr, numElements);
    INFO(ss.str());
    REQUIRE(heap.isMinHeap(heapArr, numElements) == false);
}


// 1 points
TEST_CASE("verify that isMinHeap(heapArr[],numElements) returns false when an element in a BinHeap has a non-full bottom and an invalid right child", "[ISMINHEAP][19]") { 
    BinHeap<int> heap;
    int heapArr[] = { UNUSED, 1, 7, 9, 15, 16, 21, 10, 25, 30, 18, 12 };
    int numElements = NUM_HEAP_ELEMENTS(heapArr);
    std::stringstream ss;
    printArrayContentsToStream(ss, heapArr, numElements);
    INFO(ss.str());
    REQUIRE(heap.isMinHeap(heapArr, numElements) == false);
}


/* **************************************************************** */
// REMOVE
/* **************************************************************** */


// 2 points
TEST_CASE("verify that remove(i) returns -1 when attempting to remove from an empty BinHeap", "[REMOVE][21]") {
    BinHeap<int> heap;
    int arr[] = { };
    int arrSize = 0;
    int maxHeapSize = 1;
    makeHeap(heap, arr, arrSize, maxHeapSize);
    INFO("before calling remove(), BinHeap is empty");
    REQUIRE(heap.maxSize == 1);
    REQUIRE(heap.heapSize == 0);
    REQUIRE(heap.heapArray != nullptr);
    REQUIRE(heap.heapArray[0] == -1);
    std::stringstream ss;
    heap.printHeapToStream(ss);
    INFO(ss.str());
    
    INFO("attempting to remove non-existant value at index 1, remove(1) should return -1");
    REQUIRE(heap.remove(1) == -1);
    INFO("after attempting to remove non-existant value at index 1, heap structure should be unchanged");
    REQUIRE(heap.maxSize == 1);
    REQUIRE(heap.heapSize == 0);
    REQUIRE(heap.heapArray != nullptr);
    REQUIRE(heap.heapArray[0] == -1);
}


// 1 point
TEST_CASE("verify that remove(i) operates correctly and returns -1 when i <= 0", "[REMOVE][22]") {
    BinHeap<int> heap;
    std::stringstream setupInfo;
    removeTestSetup(heap, setupInfo);
    INFO(setupInfo.str());
    
    SECTION("verify that remove(i) returns -1 when i = 0") {
        INFO("attempting to remove value from invalid index 0, remove(0) should return -1");
        REQUIRE(heap.remove(0) == -1);
        INFO("after attempting to remove value from invalid index 0, heap structure should be unchanged");
        REQUIRE(heap.maxSize == 11);
        REQUIRE(heap.heapSize == 11);
        REQUIRE(heap.heapArray != nullptr);
        REQUIRE(heap.heapArray[0] == -1);
        REQUIRE(heap.heapArray[1] == 2);
        REQUIRE(heap.heapArray[2] == 4);
        REQUIRE(heap.heapArray[3] == 6);
        REQUIRE(heap.heapArray[4] == 15);
        REQUIRE(heap.heapArray[5] == 12);
        REQUIRE(heap.heapArray[6] == 18);
        REQUIRE(heap.heapArray[7] == 8);
        REQUIRE(heap.heapArray[8] == 17);
        REQUIRE(heap.heapArray[9] == 16);
        REQUIRE(heap.heapArray[10] == 20);
        REQUIRE(heap.heapArray[11] == 14);
    }

    SECTION("verify that remove(i) returns -1 when i = -2") {
        INFO("attempting to remove value from invalid index -2, remove(-2) should return -1");
        REQUIRE(heap.remove(-2) == -1);
        INFO("after attempting to remove value from invalid index -2, heap structure should be unchanged");
        REQUIRE(heap.maxSize == 11);
        REQUIRE(heap.heapSize == 11);
        REQUIRE(heap.heapArray != nullptr);
        REQUIRE(heap.heapArray[0] == -1);
        REQUIRE(heap.heapArray[1] == 2);
        REQUIRE(heap.heapArray[2] == 4);
        REQUIRE(heap.heapArray[3] == 6);
        REQUIRE(heap.heapArray[4] == 15);
        REQUIRE(heap.heapArray[5] == 12);
        REQUIRE(heap.heapArray[6] == 18);
        REQUIRE(heap.heapArray[7] == 8);
        REQUIRE(heap.heapArray[8] == 17);
        REQUIRE(heap.heapArray[9] == 16);
        REQUIRE(heap.heapArray[10] == 20);
        REQUIRE(heap.heapArray[11] == 14);
    }
}


// 1 point
TEST_CASE("verify that remove(i) operates correctly and returns -1 when i > heapSize", "[REMOVE][23]") {
    BinHeap<int> heap;
    std::stringstream setupInfo;
    removeTestSetup(heap, setupInfo);
    INFO(setupInfo.str());
    INFO("attempting to remove value from invalid index 55, remove(55) should return -1");
    REQUIRE(heap.remove(55) == -1);
    INFO("after attempting to remove value from invalid index 55, heap structure should be unchanged");
    REQUIRE(heap.maxSize == 11);
    REQUIRE(heap.heapSize == 11);
    REQUIRE(heap.heapArray != nullptr);
    REQUIRE(heap.heapArray[0] == -1);
    REQUIRE(heap.heapArray[1] == 2);
    REQUIRE(heap.heapArray[2] == 4);
    REQUIRE(heap.heapArray[3] == 6);
    REQUIRE(heap.heapArray[4] == 15);
    REQUIRE(heap.heapArray[5] == 12);
    REQUIRE(heap.heapArray[6] == 18);
    REQUIRE(heap.heapArray[7] == 8);
    REQUIRE(heap.heapArray[8] == 17);
    REQUIRE(heap.heapArray[9] == 16);
    REQUIRE(heap.heapArray[10] == 20);
    REQUIRE(heap.heapArray[11] == 14);
}


// 4 points
TEST_CASE("verify that remove(i) operates correctly and returns the correct value when removing a leaf node", "[REMOVE][24]") {
    BinHeap<int> heap;
    std::stringstream setupInfo;
    removeTestSetup(heap, setupInfo);
    INFO(setupInfo.str());
    
    SECTION("verify that remove(i) operates correctly and returns the correct value when the leaf node is not the last node in the heap") {
        INFO("attempting to remove value from index 10, remove(10) should return 20");
        REQUIRE(heap.remove(10) == 20);
        INFO("after attempting to remove value from index 10, heap structure has changed");
        REQUIRE(heap.maxSize == 11);
        REQUIRE(heap.heapSize == 10);
        REQUIRE(heap.heapArray != nullptr);
        REQUIRE(heap.heapArray[0] == -1);
        REQUIRE(heap.heapArray[1] == 2);
        REQUIRE(heap.heapArray[2] == 4);
        REQUIRE(heap.heapArray[3] == 6);
        REQUIRE(heap.heapArray[4] == 15);
        REQUIRE(heap.heapArray[5] == 12);
        REQUIRE(heap.heapArray[6] == 18);
        REQUIRE(heap.heapArray[7] == 8);
        REQUIRE(heap.heapArray[8] == 17);
        REQUIRE(heap.heapArray[9] == 16);
        REQUIRE(heap.heapArray[10] == 14);
    }
    
    SECTION("verify that remove(i) operates correctly and returns the correct value when the leaf node is the last node in the heap") {
        INFO("attempting to remove value from index 11, remove(11) should return 14");
        REQUIRE(heap.remove(11) == 14);
        INFO("after attempting to remove value from index 10, heap structure has changed");
        REQUIRE(heap.maxSize == 11);
        REQUIRE(heap.heapSize == 10);
        REQUIRE(heap.heapArray != nullptr);
        REQUIRE(heap.heapArray[0] == -1);
        REQUIRE(heap.heapArray[1] == 2);
        REQUIRE(heap.heapArray[2] == 4);
        REQUIRE(heap.heapArray[3] == 6);
        REQUIRE(heap.heapArray[4] == 15);
        REQUIRE(heap.heapArray[5] == 12);
        REQUIRE(heap.heapArray[6] == 18);
        REQUIRE(heap.heapArray[7] == 8);
        REQUIRE(heap.heapArray[8] == 17);
        REQUIRE(heap.heapArray[9] == 16);
        REQUIRE(heap.heapArray[10] == 20);
    }
}


// 4 points
TEST_CASE("verify that remove(i) operates correctly and returns the correct value when removing a non-leaf node", "[REMOVE][25]") {
    BinHeap<int> heap;
    std::stringstream setupInfo;
    removeTestSetup(heap, setupInfo);
    INFO(setupInfo.str());
    INFO("attempting to remove value from index 2, remove(2) should return 4");
    REQUIRE(heap.remove(2) == 4);
    INFO("after attempting to remove value from index 2, heap structure has changed");
    REQUIRE(heap.maxSize == 11);
    REQUIRE(heap.heapSize == 10);
    REQUIRE(heap.heapArray != nullptr);
    REQUIRE(heap.heapArray[0] == -1);
    REQUIRE(heap.heapArray[1] == 2);
    REQUIRE(heap.heapArray[2] == 12);
    REQUIRE(heap.heapArray[3] == 6);
    REQUIRE(heap.heapArray[4] == 15);
    REQUIRE(heap.heapArray[5] == 14);
    REQUIRE(heap.heapArray[6] == 18);
    REQUIRE(heap.heapArray[7] == 8);
    REQUIRE(heap.heapArray[8] == 17);
    REQUIRE(heap.heapArray[9] == 16);
    REQUIRE(heap.heapArray[10] == 20);
}


/* **************************************************************** */
/* **************************************************************** */



/* **************************************************************** */
/* **************************************************************** */
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
/* **************************************************************** */
/* **************************************************************** */


int main( int argc, char const* const* const argv )
{
    // global setup...
    std::cout << BOLDCYAN << std::endl;
    std::cout << "###############################################################################" << std::endl;
    std::cout << "############################# Running Unit Tests ##############################" << std::endl;
    std::cout << "###############################################################################" << std::endl;
    std::cout << RESET << std::endl;

    int result = Catch::Session().run( argc, argv );

    // global clean-up...
    std::cout << BOLDCYAN << std::endl;
    std::cout << "###############################################################################" << std::endl;
    std::cout << "########################### Done Running Unit Tests ###########################" << std::endl;
    std::cout << "###############################################################################" << std::endl;
    std::cout << RESET << std::endl;

    return result;
}
