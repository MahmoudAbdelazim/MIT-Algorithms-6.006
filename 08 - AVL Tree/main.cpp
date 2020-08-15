#include <bits/stdc++.h>
#include "AVLTree.h"
#include "AVLTree.cpp"

using namespace std;

int main() {
    AVLTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);
    tree.insert(5);
    tree.erase(5);
    tree.erase(70);
    tree.erase(50);

    cout << tree.findPredecessor(30)->val << endl;

    tree.preOrderPrint();
}
