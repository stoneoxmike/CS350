//
//  BST.cpp
//

#include "BST.h"
#include "Flags.h"



/* **************************************************************** */

#if ALL || FINDPREDECESSOR
template <class T>
Node<T> * BST<T>::findPredecessor(Node<T> * node) {
    
    // TODO: This method is stubbed out, but does not return the
    // correct value.  Implement this method correctly.

    if (node->left != nullptr) {
        node = node->left;
        while (node->right != nullptr) {
            node = node->right;
        }
    } else {
        return nullptr;
    }
    return node;

}
#endif

/* **************************************************************** */

#if ALL || FINDNODEITERATIVELY
template <class T>
Node<T> * BST<T>::findNodeIteratively(Node<T> * node, const T & x) {
    
    // TODO: This method is stubbed out, but does not return the
    // correct value.  Implement this method correctly.

    if (node != nullptr) {
        while (node->left != nullptr || node->right != nullptr) {
            if (x < node->data) {
                node = node->left;
            } else if (x > node->data) {
                node = node->right;
            } else {
                return node;
            }
        }
        if (x == node->data) {
            return node;
        }
    }
    return nullptr;
    
}
#endif

/* **************************************************************** */

#if ALL || HEIGHT
template <class T>
int BST<T>::height(Node<T> * node) {

    // TODO: This method is stubbed out, but does not return the
    // correct value.  Implement this method correctly.

    if (node != nullptr) {
        if (node->left != nullptr && node->right != nullptr) {
            if (height(node->left) > height(node->right)) {
                return height(node->left) + 1;
            } else {
                return height(node->right) + 1;
            }
        }
        if (node->left != nullptr) {
            return height(node->left) + 1;
        }
        if (node->right != nullptr) {
            return height(node->right) + 1;
        }
        return 1;
    }
    return 0;

}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* **************************************************************** */
/* **************************************************************** */

// DO NOT DELETE THE FOLLOWING LINE!!!
template class BST<int>;
