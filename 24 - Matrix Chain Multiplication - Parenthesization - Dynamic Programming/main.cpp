#include <bits/stdc++.h>

using namespace std;
#define MAX 1000
vector<vector<int>> dp;

int parenthesize(int arr[], int i, int j) {
    if (i == j) return 0;
    int min = INT_MAX;
    int count = 0, count1 = 0, count2 = 0;
    // try placing parenthesis at all possible places and recurse and find the minimum cost
    for (int k = i; k < j; k++) {
        if (dp[i][k] != -1) count1 = dp[i][k];
        else count1 = parenthesize(arr, i, k);
        if (dp[k + 1][j] != -1) count2 = dp[k + 1][j];
        else count2 = parenthesize(arr, k + 1, j);
        count = count1 + count2
                + arr[i - 1] * arr[k] * arr[j]; // the cost of this scalar multiplication
        if (count < min) min = count;
    }
    return dp[i][j] = min;
}

int main() {
    int arr[] = {1, 2, 3, 4, 3};
    /*
     * arr contains the sizes of the matrices
     * Matrix 1 is 1x2, Matrix 2 is 2x3, ...
     */
    int size = 5;
    dp.assign(MAX, vector<int>(MAX, -1));
    cout << "Minimum number of multiplications is: " << parenthesize(arr, 1, size - 1) << "\n";
}
