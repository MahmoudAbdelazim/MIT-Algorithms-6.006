#include <bits/stdc++.h>

using namespace std;

template <class T>
class PriorityQueue {
private:
    vector<T> A;
    int size;
public:
    PriorityQueue() {
        A.push_back(T());
        size = 1;
    }

    void maxHeapify(int i) {
        int n = size - 1;
        int l = 2 * i;
        int r = 2 * i + 1;
        int largest = i;
        if (l <= n && A[l] > A[i])
            largest = l;
        if (r <= n && A[r] > A[largest])
            largest = r;
        if (largest != i) {
            swap(A[i], A[largest]);
            maxHeapify(largest);
        }
    }

    bool increase_key(int i, T key) {
        if (key < A[i])
            return false;
        A[i] = key;
        while (i > 1 && (A[i / 2] < A[i])) {
            swap(A[i], A[i / 2]);
            i /= 2;
        }
        return true;
    }

    void insert(T item) {
        size++;
        A.push_back(item);
        increase_key(size - 1, item);
    }

    T max() {
        return A[1];
    }

    T extract_max() {
        T max = A[1];
        swap(A[1], A[size - 1]);
        A.pop_back();
        --size;
        maxHeapify(1);
        return max;
    }
};

int main() {
    PriorityQueue<int> q;
    for (int i = 0, x; i < 5; i++) {
        cin >> x;
        q.insert(x);
    }
    for (int i = 0; i < 5; i++) {
        cout << q.extract_max() << " ";
    }
    cout << "\n";
}
