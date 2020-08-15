//
// Created by M.Abdelazim on 2020-07-09.
//

#include "BST.h"

template<class T>
BST<T>::BST() : root(nullptr), size(0) {}

/*
 * a method interface for inserting
 */
template<class T>
node<T> *BST<T>::insert(T item) {
    size++;
    return BSTInsert(item, root, nullptr);
}

/*
 * inserts an element "item" into the BST rooted at "n" whose parent is "parent"
 */
template<class T>
node<T> *BST<T>::BSTInsert(T item, node<T> *&n, node<T> *parent) {
    if (n == nullptr) { // if n is null, then this is where item should go
        n = new node<T>();
        n->val = item;
        n->parent = parent;
        return n;
    }
    if (item <= n->val) { // if item is less than n's value, then it should be in the left branch of n
        n->left = BSTInsert(item, n->left, n);
    } else {
        n->right = BSTInsert(item, n->right,
                             n); // if item is greater than n's value, then it should be in the right branch of n
    }
    return n;
}

/*
 * transplant an element v in place of an element u
 */
template<class T>
void BST<T>::transplant(node<T> *u, node<T> *v) {
    if (u->parent == nullptr) // if u is the root, make u the root
        root = v;
    else if (u == u->parent->left) // if u is a left child of its parent, make v the left child
        u->parent->left = v;
    else // if u is the right child of its parent, make v the right child
        u->parent->right = v;
    if (v != nullptr)
        v->parent = u->parent; // change v's parent to be u's parent
}

/*
 * erases an element "x" from the BST
 */
template<class T>
bool BST<T>::erase(T x) {
    node<T> *n = find(x); // find the node that contains x
    if (n == nullptr) return false; // x is not in the BST
    if (n->left == nullptr) // if n doesn't have a left child, transplant it with its right child
        transplant(n, n->right);
    else if (n->right == nullptr) // if n doesn't have a right child, transplant it with its left child
        transplant(n, n->left);
    else { // if n has both left and right child
        node<T> *y = findSuccessor(x); // find the successor of x
        if (y->parent != n) { // move the successor up in order for it to be a direct child of n
            transplant(y, y->right);
            y->right = n->right;
            y->right->parent = y;
        }
        transplant(n, y); // transplant n with with its successor (its right child)
        y->left = n->left;
        y->left->parent = y;
    }
    return true;
}

/*
 * returns the node that contains an element "item"
 */
template<class T>
node<T> *BST<T>::find(T item) {
    node<T> *tmp = root;
    while (tmp != nullptr) { //Binary search for the item
        if (item == tmp->val)
            return tmp;
        else if (item > tmp->val)
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    return nullptr; // item is not in the BST
}

/*
 * an interface for finding the minimum element node
 */
template<class T>
node<T> *BST<T>::findMin() {
    findMin(root);
}

/*
 * returns the minimum element node in a subtree rooted at n
 */
template<class T>
node<T> *BST<T>::findMin(node<T> *n) {
    node<T> *tmp = n;
    if (tmp != nullptr) {
        while (tmp->left != nullptr) { // go to the leftmost node
            tmp = tmp->left;
        }
        return tmp;
    }
    return nullptr; // the BST is empty
}

/*
 * an interface for finding the maximum element node
 */
template<class T>
node<T> *BST<T>::findMax() {
    findMax(root);
}

/*
 * returns the maximum element node in a subtree rooted at n
 */
template<class T>
node<T> *BST<T>::findMax(node<T> *n) {
    node<T> *tmp = n;
    if (tmp != nullptr) {
        while (tmp->right != nullptr) { // go to the rightmost node
            tmp = tmp->right;
        }
        return tmp;
    }
    return nullptr;
}

/*
 * returns the successor node of an element "item"
 */
template<class T>
node<T> *BST<T>::findSuccessor(T item) {
    node<T> *n = find(item); // find the node that contains item
    if (n == nullptr) return nullptr; // item is not in the BST
    if (n->right != nullptr) // find the minimum element in n's right subtree if it has a right child
        return findMin(n->right);
    node<T> *y = n->parent;
    while (y != nullptr && n == y->right) { // find the nearest node that n is a right descendent of
        n = y;
        y = n->parent;
    }
    return y; // of no successor, returns nullptr
}

/*
 * returns the predecessor node of an element "item"
 */
template<class T>
node<T> *BST<T>::findPredecessor(T item) {
    node<T> *n = find(item); // find the node that contains item
    if (n == nullptr) return nullptr; // item is not in the BST
    if (n->left != nullptr) // find the maximum element in n's left subtree if it has a left child
        return findMax(n->left);
    node<T> *y = n->parent;
    while (y != nullptr && n == y->left) { // find the nearest node that n is a left descendent of
        n = y;
        y = n->parent;
    }
    return y;
}

/*
 * In-order traversal for the BST
 */
template<class T>
void BST<T>::inOrderPrint(node<T> *n) {
    if (n == nullptr)
        n = root;
    if (n->left != nullptr)
        inOrderPrint(n->left);
    cout << n->val << " ";
    if (n->right != nullptr)
        inOrderPrint(n->right);
}

/*
 * Pre-order traversal for the BST
 */
template<class T>
void BST<T>::preOrderPrint(node<T> *n) {
    if (n == nullptr)
        n = root;
    cout << n->val << " ";
    if (n->left != nullptr)
        preOrderPrint(n->left);
    if (n->right != nullptr)
        preOrderPrint(n->right);
}

/*
 * Post-order traversal for the BST
 */
template<class T>
void BST<T>::postOrderPrint(node<T> *n) {
    if (n == nullptr)
        n = root;
    if (n->left != nullptr)
        postOrderPrint(n->left);
    if (n->right != nullptr)
        postOrderPrint(n->right);
    cout << n->val << " ";
}
