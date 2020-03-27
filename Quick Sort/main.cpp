#include <bits/stdc++.h>

using namespace std;

int partition(int A[], int p, int r) {
    int pivot = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= pivot) {
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

void quickSort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main() {
    int a[] = {9, 7, 4, 3, 6, 8, 32, 6, 8, 123, 5, 1};
    quickSort(a, 0, 11);
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
}
