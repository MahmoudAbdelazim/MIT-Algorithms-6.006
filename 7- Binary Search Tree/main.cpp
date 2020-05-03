#include <bits/stdc++.h>

using namespace std;

template <class T>
class node {
public:
    node *left;
    node *right;
    node *parent;
    T val;
    int height;
    node() : left(nullptr), right(nullptr), parent(nullptr), val(T()), height(1) {}
};

template <class T>
class BST {
private:
    node<T> *root;
    int size;
public:
    BST() : root(nullptr), size(0) {}

    node<T>* insert(T item) {
        size++;
        return BSTInsert(item, root, nullptr);
    }

    node<T>* BSTInsert(T item, node<T>* &n, node<T>* parent) {
        if (n == nullptr) {
            n = new node<T>();
            n->val = item;
            n->parent = parent;
            return n;
        }
        if (item <= n->val) {
            n->left = BSTInsert(item, n->left, n);
        }
        else {
            n->right = BSTInsert(item, n->right, n);
        }
        return n;
    }

    void transplant(node<T> *u, node<T> *v) {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        if (v != nullptr)
            v->parent = u->parent;
    }

    bool erase(T x) {
        node<T> *n = find(x);
        if (n == nullptr) return false;
        if (n->left == nullptr)
            transplant(n, n->right);
        else if (n->right == nullptr)
            transplant(n, n->left);
        else {
            node<T> *y = findSuccessor(x);
            if (y->parent != n) {
                transplant(y, y->right);
                y->right = n->right;
                y->right->parent = y;
            }
            transplant(n, y);
            y->left = n->left;
            y->left->parent = y;
        }
        return true;
    }

    node<T> *find(T item) {
        node<T> *tmp = root;
        while (tmp != nullptr) {
            if (item == tmp->val)
                return tmp;
            else if (item > tmp->val) {
                tmp = tmp->right;
            } else {
                tmp = tmp->left;
            }
        }
        return nullptr;
    }

    node<T> *findMin() {
        findMin(root);
    }

    static node<T> *findMin(node<T> *n) {
        node<T> *tmp = n;
        if (tmp != nullptr) {
            while (tmp->left != nullptr) {
                tmp = tmp->left;
            }
            return tmp;
        }
        return nullptr;
    }

    node<T> *findMax() {
        findMax(root);
    }

    static node<T> *findMax(node<T> *n) {
        node<T> *tmp = n;
        if (tmp != nullptr) {
            while (tmp->right != nullptr) {
                tmp = tmp->right;
            }
            return tmp;
        }
        return nullptr;
    }

    node<T> *findSuccessor(T item) {
        node<T> *n = find(item);
        if (n == nullptr) return nullptr;
        if (n->right != nullptr) {
            return findMin(n->right);
        }
        node<T> *y = n->parent;
        while (y != nullptr && n == y->right) {
            n = y;
            y = n->parent;
        }
        return y;
    }

    node<T> *findPredecessor(T item) {
        node<T> *n = find(item);
        if (n == nullptr) return nullptr;
        if (n->left != nullptr) {
            return findMax(n->left);
        }
        node<T> *y = n->parent;
        while (y != nullptr && n == y->left) {
            n = y;
            y = n->parent;
        }
        return y;
    }

    void inOrderPrint(node<T> *n = nullptr) {
        if (n == nullptr) {
            n = root;
        }
        if (n->left != nullptr) {
            inOrderPrint(n->left);
        }
        cout << n->val << " ";
        if (n->right != nullptr) {
            inOrderPrint(n->right);
        }
    }

    void preOrderPrint(node<T> *n = nullptr) {
        if (n == nullptr) {
            n = root;
        }
        cout << n->val << " ";
        if (n->left != nullptr)
            preOrderPrint(n->left);
        if (n->right != nullptr)
            preOrderPrint(n->right);
    }

    void postOrderPrint(node<T> *n = nullptr) {
        if (n == nullptr)
            n = root;
        if (n->left != nullptr) {
            postOrderPrint(n->left);
        }
        if (n->right != nullptr) {
            postOrderPrint(n->right);
        }
        cout << n->val << " ";
    }
};

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
