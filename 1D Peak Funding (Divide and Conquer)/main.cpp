#include <bits/stdc++.h>

using namespace std;

int peakFind(vector<int> &arr) {
    int s = 0, e = arr.size() - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (mid > 0 && mid < arr.size() - 1) {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return arr[mid];
            }
            else if (arr[mid - 1] > arr[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        } else if (mid == arr.size() - 1) {
            if (arr[mid] > arr[mid - 1]) {
                return arr[mid];
            }
            else if (arr[mid - 1] > arr[mid]) {
                e = mid - 1;
            }
        } else if (mid == 0) {
            if (arr[mid] > arr[mid + 1]) {
                return arr[mid];
            }
            else if (arr[mid + 1] > arr[mid]) {
                s = mid + 1;
            }
        }

    }
    return -1;
}

int main() {
    vector<int> arr {1, 5, 7, 8, 10, 9, 5, 6, 2};
    cout << peakFind(arr);
}
