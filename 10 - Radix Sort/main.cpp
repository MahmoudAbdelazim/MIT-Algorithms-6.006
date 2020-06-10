#include <bits/stdc++.h>

using namespace std;

void countingSort(vector<int> &v, int exp) {
    vector<int> tmp(v.size());
    int count[10] = {0};
    for (int i = 0; i < v.size(); i++) {
        count[(v[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    vector<int> res(v.size());

    for (int i = (int) v.size() - 1; i >= 0; i--) {
        res[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }
    for (int i = 0; i < v.size(); i++)
        v[i] = res[i];
}

vector<int> radixSort(vector<int> &v) {
    int m = *max_element(v.begin(), v.end());
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(v, exp);
    }
}

int main() {
    vector<int> v {9, 8, 7, 6, 10, 64, 30, 20, 100, 200, 120, 40};
    radixSort(v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
