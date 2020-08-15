//
// Created by M.Abdelazim on 2020-07-09.
//

#ifndef INC_2D_PEAK_FINDING__DIVIDE_AND_CONQUER__PEAKFIND_H
#define INC_2D_PEAK_FINDING__DIVIDE_AND_CONQUER__PEAKFIND_H

#include <iostream>
#include <vector>

using namespace std;

// Returns a peak (an element that is greater than all its adjacent neighbors) in a 2D vector 'arr'
template <class T>
int peakFind(vector<vector<T>> &arr) {
    int n = arr.size(); // number of rows
    int m = arr[0].size(); // number of columns
    int s = 0, e = m - 1; // the start and end of out search
    while (s <= e) {
        int mid = s + (e - s) / 2;
        int mx = INT_MIN;
        int mxIdx = -1;
        for (int i = 0; i < n; i++) { // get the maximum element in the current column and store it in mx
            if (arr[i][mid] > mx) {
                mx = arr[i][mid];
                mxIdx = i;
            }
        }
        if (mid > 0 && mid < m - 1) {
            // if the max element is great than its adjacent neighbors in its row, then it's a peak
            if (mx > arr[mxIdx][mid - 1] && mx > arr[mxIdx][mid + 1]) {
                return mx;
            } else if (arr[mxIdx][mid - 1] > mx) { // else if the previous element is greater, discard the right half
                e = mid - 1;
            } else { // else, discard the left half
                s = mid + 1;
            }
        } else if (mid == m - 1) { // if it's the last column, only compare it to the previous
            if (mx > arr[mxIdx][mid - 1]) {
                return mx;
            } else if (arr[mxIdx][mid - 1] > mx) {
                e = mid - 1;
            }
        } else if (mid == 0) { // if it's the first column, only compare it to the next
            if (mx > arr[mxIdx][mid + 1]) {
                return mx;
            } else if (arr[mxIdx][mid + 1] > mx) {
                s = mid + 1;
            }
        }
    }
    return -1;
}


#endif //INC_2D_PEAK_FINDING__DIVIDE_AND_CONQUER__PEAKFIND_H
