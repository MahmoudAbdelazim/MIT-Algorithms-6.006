#include <bits/stdc++.h>

using namespace std;

template<class T>
class node {
public:
    node *left;
    node *right;
    node *parent;
    T val;
    int height;

    node() : left(nullptr), right(nullptr), val(T()), height(1), parent(nullptr) {}

    int setHeight() {
        if (left == nullptr && right == nullptr)
            height = 1;
        else if (left == nullptr)
            height = right->height + 1;
        else if (right == nullptr)
            height = left->height + 1;
        else
            height = max(left->height, right->height) + 1;
    }
};

template<class T>
class AVLTree {
private:
    node<T> *root;
    int size;
public:
    AVLTree() : root(nullptr), size(0) {}

    node<T> *rightRotate(node<T> *y) {
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

    node<T> *leftRotate(node<T> *x) {
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

    int getDifference(node<T> *n) {
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

    node<T> *insert(T item) {
        size++;
        return AVLInsert(item, root, nullptr);
    }

    node<T> *AVLInsert(T item, node<T> *&n, node<T> *parent) {
        if (n == nullptr) {
            n = new node<T>();
            n->val = item;
            n->parent = parent;
            return n;
        }
        if (item <= n->val) {
            n->left = AVLInsert(item, n->left, n);
        } else {
            n->right = AVLInsert(item, n->right, n);
        }
        n->setHeight();
        return balance(n, item);
    }

    node<T> *balance(node<T> *n, T item) {
        int diff = getDifference(n);
        if (diff > 1 && item <= n->left->val)
            return rightRotate(n);
        else if (diff < -1 && item > n->right->val)
            return leftRotate(n);
        else if (diff > 1 && item > n->left->val) {
            n->left = leftRotate(n->left);
            return rightRotate(n);
        } else if (diff < -1 && item <= n->right->val) {
            n->right = rightRotate(n->right);
            return leftRotate(n);
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

    void AdjustErase(node<T> *n, T item) {
        if (n == nullptr) {
            return;
        }
        n->height--;
        balance(n, item);
        AdjustErase(n->parent, item);
    }

    bool erase(T x) {
        node<T> *n = find(x);
        if (n == nullptr) return false;
        node<T>* parent = n->parent;
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
        AdjustErase(parent, parent->val);
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
        if (n == nullptr) return n;
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
        if (n == nullptr) return n;
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
