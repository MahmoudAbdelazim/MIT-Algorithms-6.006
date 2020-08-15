#include <bits/stdc++.h>

using namespace std;

template <class T>
void maxHeapify(vector<T> &A, int i, int n) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = i;
    if (l <= n && A[l] > A[i])
        largest = l;
    if (r <= n && A[r] > A[largest])
        largest = r;
    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, largest, n);
    }
}

template <class T>
void buildMaxHeap(vector<T> &A, int n) {
    for (int i = n / 2; i >= 1; i--) {
        maxHeapify(A, i, n);
    }
}

template <class T>
void heapSort(vector<T> &A, int n) {
    buildMaxHeap(A, n);
    for (int i = n; i >= 1; i--) {
        swap(A[1], A[i]);
        maxHeapify(A, 1, i - 1);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    heapSort<int>(arr, n);
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
