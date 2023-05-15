//
//  HashTable.cpp
//

#include "HashTable.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
HashTable::HashTable(int tableSize)
{
    // TODO: Constructor
    table = new Node*[tableSize];
    size = tableSize;
    for (int i = 0; i < tableSize; i++) {
        table[i] = nullptr;
    }
}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
HashTable::~HashTable()
{
    // TODO: Destructor
    for (int i = 0; i < size; i++) {
        Node *node = table[i];
        while (node != nullptr) {
            table[i] = node->next;
            delete node;
            node = table[i];
        }
    }
    delete[] table;
}
#endif

/* **************************************************************** */

#if INSERT || ALL
// TODO: insert() method
void HashTable::insert(std::string x) {
    Node* head = table[hash(x)];
    if (!find(x)) {
        Node* node = new Node(x, head);
        table[hash(x)] = node;
    }
}
#endif

/* **************************************************************** */

#if FIND || ALL
// TODO: find() method
bool HashTable::find(std::string x) {
    bool inList = false;
    Node* node = table[hash(x)];
    while (node != nullptr) {
        if (node->data == x) {
            inList = true;
        }
        node = node->next;
    }
    return inList;
}
#endif

/* **************************************************************** */

#if REMOVE || ALL
// TODO: remove() method
void HashTable::remove(std::string x) {
    if (find(x)) {
        Node *node = table[hash(x)];
        if (node->data == x) {
            table[hash(x)] = node->next;
            delete node;
        } else {
            while (node->next->data != x) {
                node = node->next;
            }
            Node *next = node->next;
            node->next = node->next->next;
            delete next;
        }
    }
}
#endif

/* **************************************************************** */

#if LOADFACTOR || ALL
// TODO: loadFactor() method
float HashTable::loadFactor() {
    int count = 0;
    for (int i = 0; i < size; i++) {
        Node* node = table[i];
        while (node != nullptr) {
            count++;
            node = node->next;
        }
    }
    return (float) count / (float) size;
}
#endif

/* **************************************************************** */

#if MAXCHAINLENGTH || ALL
// TODO: maxChainLength() method
void HashTable::maxChainLength(int &maxLength, int &maxSlotIndex) {
    maxSlotIndex = 0;
    maxLength = 0;
    Node* node;
    for (int i = 0; i < size; i++) {
        if (table[i] != nullptr) {
            node = table[i];
            int count = 0;
            while (node != nullptr) {
                count++;
                node = node->next;
            }
            if (count > maxLength) {
                maxLength = count;
                maxSlotIndex = i;
            }
        }
    }
}
#endif

/* **************************************************************** */

#if NUMEMPTYSLOTS || ALL
// TODO: numEmptySlots() method
int HashTable::numEmptySlots() {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (table[i] == nullptr) {
            count++;
        }
    }
    return count;
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
unsigned int HashTable::hash(std::string x) {
    unsigned int hashCode = 0;
    std::string::iterator it;
    for (it=x.begin(); it < x.end(); it ++) {
        hashCode = *it + (hashCode << 5) - hashCode;
    }
    return hashCode % size;
}


void HashTable::printHashTable() {
    std::stringstream ss;
    printHashTableToStream(ss);
    std::cout << ss.str();
}


void HashTable::printHashTableToStream(std::stringstream& ss) {
    Node* node;
    // Iterate over table
    for (int i = 0; i < size; i++) {
        ss << "[" << i << "]: ";
        // Iterate over list
        node = table[i];
        while (node != nullptr) {
            ss << node->data << " -> ";
            node = node->next;
        }
        ss << "nullptr" << std::endl;
    }
}
#endif
