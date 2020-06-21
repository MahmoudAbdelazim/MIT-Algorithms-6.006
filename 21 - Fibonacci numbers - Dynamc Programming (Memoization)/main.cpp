#include <bits/stdc++.h>
using namespace std;

unordered_map<int, long long> memo;
long long fib(int n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    if (n <= 2) return memo[n] = 1;
    else return memo[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    cout << fib(49) << "\n";
}
