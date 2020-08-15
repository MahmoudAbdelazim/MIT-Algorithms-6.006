//
// Created by M.Abdelazim on 2020-07-09.
//

#ifndef BINARY_SEARCH_TREE_BST_H
#define BINARY_SEARCH_TREE_BST_H

#include <iostream>
#include "node.h"
#include "node.cpp"

using namespace std;

/*
 * a BST object is an implementation of a Binary Search Tree which supports the following operations:
 * insert, erase, find, findMin, findMax, findSuccessor, findPredecessor
 */
template<class T>
class BST {
private:
    node<T> *root;
    int size;
public:
    BST();

    node<T> *insert(T item);

    node<T> *BSTInsert(T item, node<T> *&n, node<T> *parent);

    void transplant(node<T> *u, node<T> *v);

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


#endif //BINARY_SEARCH_TREE_BST_H
