#include <bits/stdc++.h>

using namespace std;

long long fib(int n) {
    vector<long long> table(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i <= 2) table[i] = 1;
        else {
            table[i] = table[i - 1] + table[i - 2];
        }
    }
    return table[n];
}

int main() {
    cout << fib(49) << "\n";
}
