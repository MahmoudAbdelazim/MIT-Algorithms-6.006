#include <bits/stdc++.h>
#include "BST.h"
#include "BST.cpp"

using namespace std;

int main() {
    BST<string> b;
    b.insert("d");
    b.insert("b");
    b.insert("a");
    b.insert("c");
    b.insert("f");
    b.insert("e");
    b.insert("g");
    b.erase("f");


    b.inOrderPrint();
}
