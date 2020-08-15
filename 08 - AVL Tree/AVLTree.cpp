//
// Created by mahmoud on 8/16/20.
//

#include "AVLTree.h"

template<class T>
AVLTree<T>::AVLTree() : root(nullptr), size(0) {}

/*
 * Rotates the Binary Tree to the right, making the right child to be parent
 */
template<class T>
node<T> *AVLTree<T>::rightRotate(node<T> *y) {
    node<T> *x = y->left;
    node<T> *t = x->right;
    x->right = y;
    y->left = t;
    x->parent = y->parent;
    y->parent = x;
    if (y == root) {
        root = x;
    }
    y->setHeight();
    x->setHeight();
    return x;
}

/*
 * Rotates the binary tree to the left, making the left child to be parent
 */
template<class T>
node<T> *AVLTree<T>::leftRotate(node<T> *x) {
    node<T> *y = x->right;
    node<T> *t = y->left;
    y->left = x;
    x->right = t;
    y->parent = x->parent;
    x->parent = y;
    if (x == root) {
        root = y;
    }
    y->setHeight();
    x->setHeight();
    return y;
}

/*
 * Gets the difference in height between the right branch and the left branch
 */
template<class T>
int AVLTree<T>::getDifference(node<T> *n) {
    if (n == nullptr)
        return 0;
    if (n->left == nullptr && n->right == nullptr)
        return 0;
    if (n->left == nullptr)
        return -n->right->height;
    if (n->right == nullptr)
        return n->left->height;
    return n->left->height - n->right->height;
}

/*
 * a method interface for inserting
 */
template<class T>
node<T> *AVLTree<T>::insert(T item) {
    size++;
    return AVLInsert(item, root, nullptr);
}

/*
 * inserts an element "item" into the AVL Tree rooted at "n" whose parent is "parent"
 */
template<class T>
node<T> *AVLTree<T>::AVLInsert(T item, node<T> *&n, node<T> *parent) {
    if (n == nullptr) { // if n is null, then this is where item should go
        n = new node<T>();
        n->val = item;
        n->parent = parent;
        return n;
    }
    if (item <= n->val) { // if item is less than n's value, then it should be in the left branch of n
        n->left = AVLInsert(item, n->left, n);
    } else {
        n->right = AVLInsert(item, n->right, n); // if item is greater than n's value, then it should be in the right branch of n
    }
    n->setHeight(); //set the height of the current node
    return balance(n, item); // balance the AVL Tree
}

/*
 * Balances the AVLTree at a specific node
 * if the difference between the two branches is more than 1, a rotation is done
 */
template<class T>
node<T> *AVLTree<T>::balance(node<T> *n, T item) {
    int diff = getDifference(n);
    if (diff > 1 && item <= n->left->val) // if right branch is bigger and item is less than the left child, rotate right
        return rightRotate(n);
    else if (diff < -1 && item > n->right->val) // if left branch is bigger and item is more than the right child, rotate left
        return leftRotate(n);
    else if (diff > 1 && item > n->left->val) { // if right branch is bigger and item is more than the left child, then the left branch must be balanced first and then rotate right
        n->left = leftRotate(n->left);
        return rightRotate(n);
    } else if (diff < -1 && item <= n->right->val) { // if the left branch is bigger and item is less than the right child, then the right branch must be balanced first and then rotate left
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    // if the tree is already balanced, return the node
    return n;
}

/*
 * transplant an element v in place of an element u
 */
template<class T>
void AVLTree<T>::transplant(node<T> *u, node<T> *v) {
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
 * erases an element "x" from the AVL Tree
 */
template<class T>
bool AVLTree<T>::erase(T x) {
    node<T> *n = find(x); // find the node that contains x
    if (n == nullptr) return false; // x is not in the Tree
    node<T>* parent = n->parent;
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
    AdjustErase(parent, parent->val); // ensures the balance of the tree after an erase
    return true;
}

/*
 * Calls balance on the parents of the erased node from bottom to top
 */
template<class T>
void AVLTree<T>::AdjustErase(node<T> *n, T item) {
    if (n == nullptr) {
        return;
    }
    n->height--; // decrease the height of the node (because a child has been erased)
    balance(n, item); // balance the AVL Tree at node n
    AdjustErase(n->parent, item); // recurse to the parent
}

/*
 * returns the node that contains an element "item"
 */
template<class T>
node<T> *AVLTree<T>::find(T item) {
    node<T> *tmp = root;
    while (tmp != nullptr) { //Binary search for the item
        if (item == tmp->val)
            return tmp;
        else if (item > tmp->val) {
            tmp = tmp->right;
        } else {
            tmp = tmp->left;
        }
    }
    return nullptr; // item is not in the Tree
}

/*
 * an interface for finding the minimum element node
 */
template<class T>
node<T> *AVLTree<T>::findMin() {
    findMin(root);
}

/*
 * returns the minimum element node in a subtree rooted at n
 */
template<class T>
node<T> *AVLTree<T>::findMin(node<T> *n) {
    node<T> *tmp = n;
    if (tmp != nullptr) {
        while (tmp->left != nullptr) {// go to the leftmost node
            tmp = tmp->left;
        }
        return tmp;
    }
    return nullptr; // the Tree is empty
}

/*
 * an interface for finding the maximum element node
 */
template<class T>
node<T> *AVLTree<T>::findMax() {
    findMax(root);
}

/*
 * returns the maximum element node in a subtree rooted at n
 */
template<class T>
node<T> *AVLTree<T>::findMax(node<T> *n) {
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
node<T> *AVLTree<T>::findSuccessor(T item) {
    node<T> *n = find(item); // find the node that contains item
    if (n == nullptr) return nullptr; // item is not in the Tree
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
node<T> *AVLTree<T>::findPredecessor(T item) {
    node<T> *n = find(item); // find the node that contains item
    if (n == nullptr) return nullptr; // item is not in the Tree
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
 * In-order traversal for the Tree
 */
template<class T>
void AVLTree<T>::inOrderPrint(node<T> *n) {
    if (n == nullptr)
        n = root;
    if (n->left != nullptr)
        inOrderPrint(n->left);
    std::cout << n->val << " ";
    if (n->right != nullptr)
        inOrderPrint(n->right);
}

/*
 * Pre-order traversal for the Tree
 */
template<class T>
void AVLTree<T>::preOrderPrint(node<T> *n) {
    if (n == nullptr)
        n = root;
    std::cout << n->val << " ";
    if (n->left != nullptr)
        preOrderPrint(n->left);
    if (n->right != nullptr)
        preOrderPrint(n->right);
}

/*
 * Post-order traversal for the Tree
 */
template<class T>
void AVLTree<T>::postOrderPrint(node<T> *n) {
    if (n == nullptr)
        n = root;
    if (n->left != nullptr)
        postOrderPrint(n->left);
    if (n->right != nullptr)
        postOrderPrint(n->right);
    std::cout << n->val << " ";
}