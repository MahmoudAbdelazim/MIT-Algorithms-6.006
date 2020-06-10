#include <bits/stdc++.h>

using namespace std;

vector<int> countingSort(vector<int> &v, int k) {
    ++k;
    vector<int> C(k);
    for (int i = 1; i < v.size(); i++) {
        C[v[i]]++;
    }
    for (int i = 1; i < k + 1; i++) {
        C[i] += C[i - 1];
    }
    vector<int> B((int)v.size());
    for (int i = (int)v.size() - 1; i >= 1; i--) {
        B[C[v[i]]] = v[i];
        C[v[i]]--;
    }
    return B;
}

int main() {
    vector<int> v{0, 7, 12, 16, 10, 3, 120, 2, 5, 7, 200}; // 1-based array
    v = countingSort(v, *max_element(v.begin(), v.end()));
    for (int i : v)
        cout << i << " ";
    cout << endl;
}
