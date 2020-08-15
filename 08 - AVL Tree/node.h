//
// Created by mahmoud on 8/16/20.
//

#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H
#include <iostream>
#include <cmath>

/*
 * A node object keeps track of it's left child, right child and parent
 * it also has a height (from the root) and a value associated with it
 */
template<class T>
class node {
public:
    node *left;
    node *right;
    node *parent;
    T val;
    int height;

    node();

    void setHeight();
};

#endif //AVL_TREE_NODE_H
