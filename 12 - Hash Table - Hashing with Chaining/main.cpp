#include <bits/stdc++.h>
using namespace std;

template <class T1, class T2>
class hashTable {
private:
    int t;
    std::hash<T1> hash;
    list<pair<T1, T2>>** arr;
public:
    hashTable() {
        t = 99;
        arr = new list<pair<T1, T2>>*[t]();
    }

    hashTable(int size) {
        t = size;
        arr = new list<pair<T1, T2>>*[t]();
    }

    int hashFunction(T1 key) {
        //division method:
        return hash(key) % t;
    }
    void insert(T1 key, T2 val) { // O(1)
        int k = hashFunction(key);
        pair<T1, T2> obj = make_pair(key, val);
        if (arr[k] == nullptr) {
            arr[k] = new list<pair<T1, T2>>();
        }
        arr[k]->push_back(obj);
    }
    T2& find(T1 key) { // O(arr[k].size()) ~ O(1)
        int k = hashFunction(key);
        if (arr[k] == nullptr) return std::exception();
        auto it = arr[k]->begin();
        while (it != arr[k]->end()) {
            if (it->first == key) {
                return it->second;
            }
        }
        return std::exception();
    }
    void erase(T1 key) { // O(arr[k].size()) ~ O(1)
        int k = hashFunction(key);
        if (arr[k] == nullptr) return;
        for (auto it = arr[k]->begin(); it != arr[k]->end(); it++) {
            if (it->first == key) {
                arr[k]->erase(it);
                break;
            }
        }
    }

    T2& operator[](T1 key) {
        int k = hashFunction(key);
        if (arr[k] == nullptr) {
            arr[k] = new list<pair<T1, T2>>();
        }
        for (auto it = arr[k]->begin(); it != arr[k]->end(); it++) {
            if (it->first == key) {
                return it->second;
            }
        }
        pair<T1, T2> obj = make_pair(key, T2());
        arr[k]->push_back(obj);
        return operator[](key);
    }

    void printAll() {
        for (int i = 0; i < t; i++) {
            if (arr[i] != nullptr) {
                for (auto it = arr[i]->begin(); it != arr[i]->end(); it++) {
                    cout << it->first << " : " << it->second << "\n";
                }
            }
        }
    }
};

int main() {
    hashTable<string, string> h(99);
    h.insert("name", "Mahmoud");
    h.insert("job", "Developer");
    h.insert("address", "Tadamon St");
    h.insert("Age", "20");
    h.printAll();
    h.erase("Age");
    h.printAll();
    h["skin"] = "white";
    cout << h["skin"] << endl;
    h["hairColor"] = "black";
    cout << h["hairColor"] << endl;
    return 0;
}
