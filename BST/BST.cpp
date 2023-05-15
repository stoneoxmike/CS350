//
//  BST.cpp
//

#include "BST.h"
#include "Flags.h"

/* **************************************************************** */

#if ALL || CONSTRUCTOR
template <class T>
BST<T>::BST()
{
     // TODO: Initialize root
     root = nullptr;
     numNodes = 0;
}
#endif

/* **************************************************************** */

#if ALL || DESTRUCTOR
template <class T>
BST<T>::~BST()
{
    // TODO: Remove any nodes
    makeEmpty();
}
#endif

/* **************************************************************** */

#if ALL || ISEMPTY
// TODO: isEmpty() method
template <class T>
bool BST<T>::isEmpty() {
    return (root == nullptr && numNodes == 0);
}
#endif

/* **************************************************************** */

#if ALL || FIND
// TODO: find() method
template <class T>
bool BST<T>::find(const T &x) {
    if (findNode(root, x) == nullptr) {
        return false;
    } else {
        return true;
    }
}
#endif

/* **************************************************************** */

#if ALL || FINDMIN
// TODO: findMin() method
template <class T>
const T &BST<T>::findMin() {
    if (isEmpty()) {
        throw 1;
    } else {
        return findMinNode(root)->data;
    }
}
#endif

/* **************************************************************** */

#if ALL || FINDMAX
// TODO: findMax() method
template <class T>
const T &BST<T>::findMax() {
    if (isEmpty()) {
        throw 1;
    } else {
        return findMaxNode(root)->data;
    }
}
#endif

/* **************************************************************** */

#if ALL || INSERT
// TODO: insert() method
template <class T>
void BST<T>::insert(const T &x) {
    if (isEmpty()) {
        root = new Node<T>(x);
        numNodes++;
    } else {
        insertNode(root, x);
    }
}
#endif

/* **************************************************************** */

#if ALL || REMOVE
// TODO: remove() method
template <class T>
void BST<T>::remove(const T &x) {
    Node<T> *node = findNode(root, x);
    if (node != nullptr) {
        Node<T> *parent = findParentOf(x);
        if (node->left == nullptr && node->right == nullptr) {
            if (parent == nullptr) {
                makeEmpty();
            } else if (parent->left == node) {
                delete node;
                parent->left = nullptr;
                numNodes--;
            } else if (parent->right == node) {
                delete node;
                parent->right = nullptr;
                numNodes--;
            }
        } else if (node->left == nullptr || node->right == nullptr) {
            if (node->left != nullptr) {
                Node<T> *left = node->left;
                node->data = node->left->data;
                node->left = left->left;
                node->right = left->right;
                delete left;
            } else {
                Node<T> *right = node->right;
                node->data = node->right->data;
                node->left = right->left;
                node->right = right->right;
                delete right;
            }
            numNodes--;
        } else if (node->left != nullptr && node->right != nullptr) {
            Node<T> *succ = findSuccessor(node);
            parent = findParentOf(succ->data);
            node->data = succ->data;
            if (succ->right == nullptr) {
                if (parent->left == succ) {
                    delete succ;
                    parent->left = nullptr;
                } else {
                    delete succ;
                    parent->right = nullptr;
                }
                numNodes--;
            } else if (succ->right != nullptr) {
                parent->right = succ->right;
                delete succ;
                numNodes--;
            }
        }
    }
}
#endif

/* **************************************************************** */

#if ALL || MAKEEMPTY
// TODO: makeEmpty() method
template <class T>
void BST<T>::makeEmpty() {
    removeAllNodes(root);
    root = nullptr;
    numNodes = 0;
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/*  Private methods                                                 */
/* **************************************************************** */
#if ALL || FINDNODE
// TODO: findNode() private method
template <class T>
Node<T> *BST<T>::findNode(Node<T> *node, const T &x) {
    if (node == nullptr || x == node->data) {
        return node;
    } else if (x < node->data) {
        return findNode(node->left, x);
    } else {
        return findNode(node->right, x);
    }
}
#endif

/* **************************************************************** */

#if ALL || FINDMINNODE
// TODO: findMinNode() private method
template <class T>
Node<T> *BST<T>::findMinNode(Node<T> *node) {
    if (isEmpty()) {
        return nullptr;
    } else {
        if (node->left == nullptr) {
            return node;
        } else {
            return findMinNode(node->left);
        }
    }
}
#endif

/* **************************************************************** */

#if ALL || FINDMAXNODE
// TODO: findMaxNode() private method
template <class T>
Node<T> *BST<T>::findMaxNode(Node<T> *node) {
    if (isEmpty()) {
        return nullptr;
    } else {
        if (node->right == nullptr) {
            return node;
        } else {
            return findMaxNode(node->right);
        }
    }
}
#endif

/* **************************************************************** */

#if ALL || INSERTNODE
// TODO: insertNode() private method
template <class T>
Node<T> *BST<T>::insertNode(Node<T> *node, const T &x) {
    if (node == nullptr) {
        node = new Node<T>(x);
        numNodes++;
    } else if (x < node->data) {
        node->left = insertNode(node->left, x);
    } else if (x > node->data) {
        node->right = insertNode(node->right, x);
    }
    return node;
}
#endif

/* **************************************************************** */

#if ALL || FINDSUCCESSOR
// TODO: findSuccessor() private method
template <class T>
Node<T> *BST<T>::findSuccessor(Node<T> *node) {
    if (node->right != nullptr) {
        return findMinNode(node->right);
    } else {
        return nullptr;
    }
}
#endif

/* **************************************************************** */

#if ALL || FINDPARENTOF
// TODO: findParentOf() private method
template <class T>
Node<T> *BST<T>::findParentOf(const T &x) {
    Node<T> *node = root;
    if (isEmpty() || x == node->data) {
        return nullptr;
    } else {
        while (node->left != nullptr || node->right != nullptr) {
            if (x < node->data) {
                if (x == node->left->data) {
                    return node;
                }
                node = node->left;
            } else if (x > node->data) {
                if (x == node->right->data) {
                    return node;
                }
                node = node->right;
            }
        }
        return nullptr;
    }
}
#endif

/* **************************************************************** */

#if ALL || REMOVEALLNODES
// TODO: removeAllNodes() private method
template <class T>
void BST<T>::removeAllNodes(Node<T> *node) {
    if (node != nullptr) {
        if (node->left != nullptr) {
            removeAllNodes(node->left);
        }
        if (node->right != nullptr) {
            removeAllNodes(node->right);
        }
        delete node;
        numNodes--;
    }
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
// Print tree
template <class T>
void BST<T>::printTree()
{
    if (!isEmpty())
    {
        printNodesInOrder(root);
        std::cout << std::endl;
    } else {
        std::cout << "Empty Tree" << std::endl;
    }
}

// Print tree using level order traversal
template <class T>
void BST<T>::printNodesInOrder(Node<T> * node)
{
    Node<T>*q[100];
    int head = 0;
    int tail = 0;
    q[0] = root;
    tail++;
    
    while (head != tail) {
        Node<T> *n = q[head];
        head++;
        std::cout << "Node " << n->data << " ";
        if (n->left != nullptr) {
            std::cout << " left child: " << n->left->data;
            q[tail] = n->left;
            tail++;
        }
        if (n->right != nullptr) {
            std::cout << " right child: " << n->right->data;
            q[tail] = n->right;
            tail++;
        }
        
        if (n->left == nullptr && n->right == nullptr) {
            std::cout << " no children";
        }
        std::cout << std::endl;
    }
}
#endif

template class BST<int>;
