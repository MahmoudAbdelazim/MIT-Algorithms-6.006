//
// Created by M.Abdelazim on 2020-07-09.
//

#ifndef INC_1D_PEAK_FUNDING__DIVIDE_AND_CONQUER__PEAKFIND_H
#define INC_1D_PEAK_FUNDING__DIVIDE_AND_CONQUER__PEAKFIND_H

#include <iostream>
#include <vector>

using namespace std;

// Returns a peak (an element that is greater than its previous and its next element) in the vector 'arr'
template<class T>
int peakFind(vector<T> &arr) {
    int n = arr.size();
    int s = 0, e = n - 1; // the start and the end point of our search
    while (s <= e) {
        int mid = s + (e - s) / 2; //pick the middle item and decide whether it's a peak or not
        if (mid > 0 && mid < n - 1) {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return arr[mid];
            } else if (arr[mid - 1] > arr[mid]) { // if the previous item is bigger, discard the right half
                e = mid - 1;
            } else { // else, discard the left half
                s = mid + 1;
            }
        }
        else if (mid == n - 1) { // if it's the last element, only compare it to the previous
            if (arr[mid] > arr[mid - 1]) {
                return arr[mid];
            } else {
                e = mid - 1;
            }
        } else if (mid == 0) { // if it's the first element, only compare it to the next
            if (arr[mid] > arr[mid + 1]) {
                return arr[mid];
            } else {
                s = mid + 1;
            }
        }
    }
    return -1;
}

#endif //INC_1D_PEAK_FUNDING__DIVIDE_AND_CONQUER__PEAKFIND_H
