#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &A, int s, int mid, int e);
void mergeSort(vector<int> &A, int s, int e);

/*
 * Applies the divide an conquer approach on the entire array
 * dividing it into halves and calling the merge() operation on
 * each subset
 */
void mergeSort(vector<int> &A, int s, int e) {
    if (s < e) {
        int mid = (s + e) / 2;
        mergeSort(A, s, mid);
        mergeSort(A, mid + 1, e);
        merge(A, s, mid + 1, e);
    }
}

/*
 * merges two halves together
 */
void merge(vector<int> &A, int s, int mid, int e) {
    vector<int> temp(A.size()); // a temp array to store the result of merging the two halves
    int i = s, j = mid, k = s;
    while (i <= mid - 1 && j <= e) { // stores elements in temp in the right order
        if (A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
        }
    }
    while (i <= mid - 1) { // if there are still elements in the right half, add it
        temp[k++] = A[i++];
    }
    while (j <= e) { // if there are still elements in the left half, add it
        temp[k++] = A[j++];
    }
    for (i = s; i <= e; i++) //copy elements from the temp array to the actual array
        A[i] = temp[i];
}

int main() {
    vector<int> A {5, 4, 6, 2, 3, 7, 2, 10, 20, 10, 20};
    mergeSort(A, 0, A.size()-1);
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
