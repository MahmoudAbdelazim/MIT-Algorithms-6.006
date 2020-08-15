#include <iostream>
#include <vector>

#include "peakFind.h"

using namespace std;

int main() {
    vector<vector<int>> arr {
            {10, 8,  10, 10},
            {14, 13, 12, 11},
            {15, 9,  11, 10},
            {16, 17, 19, 20}
    };
    cout << peakFind(arr) << endl; // outputs "20"
}
