#include <iostream>
#include <vector>

#include "peakFind.h"

using namespace std;

int main() {
    vector<int> arr {1, 5, 7, 8, 10, 9, 5, 6, 2};
    cout << peakFind(arr); // outputs "10"
}
