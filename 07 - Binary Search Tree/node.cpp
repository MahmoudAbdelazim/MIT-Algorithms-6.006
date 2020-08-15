//
// Created by M.Abdelazim on 2020-07-09.
//

#include "node.h"

template<class T>
node<T>::node() : left(nullptr), right(nullptr), parent(nullptr), val(T()), height(1) {}
