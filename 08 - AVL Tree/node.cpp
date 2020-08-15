//
// Created by mahmoud on 8/16/20.
//

#include "node.h"

template<class T>
node<T>::node() : left(nullptr), right(nullptr), val(T()), height(1), parent(nullptr) {}

/*
 * Sets the height of the node based on the height of it's children (left and right)
 */
template<class T>
void node<T>::setHeight() {
    if (left == nullptr && right == nullptr)
        height = 1;
    else if (left == nullptr)
        height = right->height + 1;
    else if (right == nullptr)
        height = left->height + 1;
    else
        height = std::max(left->height, right->height) + 1;
}
