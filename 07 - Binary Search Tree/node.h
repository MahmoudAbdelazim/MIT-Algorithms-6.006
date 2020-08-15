//
// Created by M.Abdelazim on 2020-07-09.
//

#ifndef BINARY_SEARCH_TREE_NODE_H
#define BINARY_SEARCH_TREE_NODE_H

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
};

#endif //BINARY_SEARCH_TREE_NODE_H
