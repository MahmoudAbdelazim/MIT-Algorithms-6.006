#include <bits/stdc++.h>

using namespace std;

template <class T> // This is the simplest implementation of a hash table, where it's implemented exactly like an array with direct addressing
class hashTable {
    int t;
    pair<int, T>** arr;
public:
    hashTable(int size) {
        t = size;
        arr = new pair<int, T>*[t]();
    }
    bool insert(int key, T val) {
        if (key >= t || key < 0)
            return false;
        arr[key] = new pair<int, T>(make_pair(key, val));
        return true;
    }
    bool erase(int key) {
        if (key < 0 || key >= t)
            return false;
        arr[key] = nullptr;
        return true;
    }
    T& operator[](int i) {
        if (arr[i] == nullptr) {
            arr[i] = new pair<int, T>();
        }
        return arr[i]->second;
    }
    void printAll() {
        for (int i = 0; i < t; i++) {
            if (arr[i] != nullptr) {
                cout << arr[i]->first << " : " << arr[i]->second << "\n";
            }
        }
    }
};

int main() {
    hashTable<string> h(10);
    h.insert(5, "Mahmoud");
    h.insert(6, "Abdelazim");
    h.printAll();
    h.erase(5);
    h.printAll();
    cout << h[6] << endl;
    return 0;
}
