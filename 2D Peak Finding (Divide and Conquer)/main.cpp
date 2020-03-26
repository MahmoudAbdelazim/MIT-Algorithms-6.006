#include <bits/stdc++.h>

using namespace std;

int peakFind(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    int s = 0, e = m - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        int mx = -1e9;
        int mxIdx = -1;
        for (int i = 0; i < n; i++) {
            mx = max(mx, arr[i][mid]);
            mxIdx = i;
        }
        if (mid > 0 && mid < m - 1) {
            if (mx > arr[mxIdx][mid - 1] && mx > arr[mxIdx][mid + 1]) {
                return mx;
            } else if (arr[mxIdx][mid - 1] > mx) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        } else if (mid == m - 1) {
            if (mx > arr[mxIdx][mid - 1]) {
                return mx;
            } else if (arr[mxIdx][mid - 1] > mx) {
                e = mid - 1;
            }
        } else if (mid == 0) {
            if (mx > arr[mxIdx][mid + 1]) {
                return mx;
            } else if (arr[mxIdx][mid + 1] > mx) {
                s = mid + 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> arr{
            {10, 8,  10, 10},
            {14, 13, 12, 11},
            {15, 9,  11, 10},
            {16, 17, 19, 20}
    };
    cout << peakFind(arr) << endl;
}
