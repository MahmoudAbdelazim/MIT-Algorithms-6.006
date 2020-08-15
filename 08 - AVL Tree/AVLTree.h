//
// Created by mahmoud on 8/16/20.
//

#ifndef AVL_TREE_AVLTREE_H
#define AVL_TREE_AVLTREE_H

#include <iostream>
#include "node.h"
#include "node.cpp"

/*
 * an AVLTree object is an implementation of an AVL Balanced Binary Tree which supports the following operations:
 * insert, erase, find, findMin, findMax, findSuccessor, findPredecessor
 */
template<class T>
class AVLTree {
private:
    node<T> *root;
    int size;
public:
    AVLTree();

    node<T> *rightRotate(node<T> *y);

    node<T> *leftRotate(node<T> *x);

    int getDifference(node<T> *n);

    node<T> *insert(T item);

    node<T> *AVLInsert(T item, node<T> *&n, node<T> *parent);

    node<T> *balance(node<T> *n, T item);

    void transplant(node<T> *u, node<T> *v);

    void AdjustErase(node<T> *n, T item);

    bool erase(T x);

    node<T> *find(T item);

    node<T> *findMin();

    static node<T> *findMin(node<T> *n);

    node<T> *findMax();

    static node<T> *findMax(node<T> *n);

    node<T> *findSuccessor(T item);

    node<T> *findPredecessor(T item);

    void inOrderPrint(node<T> *n = nullptr);

    void preOrderPrint(node<T> *n = nullptr);

    void postOrderPrint(node<T> *n = nullptr);
};


#endif //AVL_TREE_AVLTREE_H
