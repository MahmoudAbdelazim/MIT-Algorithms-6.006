#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &A, int s, int mid, int e);
void mergeSort(vector<int> &A, int s, int e);

void mergeSort(vector<int> &A, int s, int e) {
    if (s < e) {
        int mid = s + (e - s) / 2;
        mergeSort(A, s, mid);
        mergeSort(A, mid + 1, e);
        merge(A, s, mid, e);
    }
    return;
}

void merge(vector<int> &A, int s, int mid, int e) {
    vector<int> L(mid - s + 1);
    vector<int> R(e - mid);
    for (int i = 0; i < L.size(); i++) {
        L[i] = A[i + s];
    }
    for (int i = 0; i < R.size(); i++) {
        R[i] = A[i + mid + 1];
    }
    L.push_back(1e9);
    R.push_back(1e9);
    int i = 0, j = 0, k = s;
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < L.size()) {
        A[k] = L[i];
        i++, k++;
    }
    while (j < R.size()) {
        A[k] = R[j];
        j++, k++;
    }
}

int main() {
    vector<int> A {5, 4, 6, 2, 3, 7, 2, 10, 20, 10, 20};
    mergeSort(A, 0, A.size()-1);
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
