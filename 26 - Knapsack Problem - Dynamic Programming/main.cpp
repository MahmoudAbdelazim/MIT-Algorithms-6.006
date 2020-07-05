#include <bits/stdc++.h>

using namespace std;
#define MAX 1000
vector<vector<int>> dp;

int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) return 0; // if the knapsack is full or there are no items left, put nothing
    if (wt[n - 1] > W) { // if the weight of this item is larger than the remaining space, skip it
        if (dp[n - 1][W] != -1) return dp[n - 1][W];
        return dp[n - 1][W] = knapsack(W, wt, val, n - 1);
    } else {
        int option1, option2;
        if (dp[n - 1][W] != -1) option1 = dp[n - 1][W];
        else option1 = dp[n - 1][W] = knapsack(W, wt, val, n - 1);
        if (dp[n - 1][W - wt[n - 1]] != -1) option2 = val[n - 1] + dp[n - 1][W - wt[n - 1]];
        else option2 = dp[n - 1][W - wt[n - 1]] = val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1);
        // either take this item or leave it
        return max(option1, option2);
    }
}

int knapsackTabulization(int W, int wt[], int val[], int n) {
    int table[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) // if the knapsack is full or there are no items left, put nothing
                table[i][w] = 0;
            else if (wt[i - 1] > w) { // if the weight of this item is larger than the remaining space, skip it
                table[i][w] = table[i - 1][w];
            }
            else {
                table[i][w] = max(table[i - 1][w],
                        val[i - 1] + table[i - 1][w - wt[i - 1]]); // either take this item or leave it
            }
        }
    }
    return table[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = 3;
    dp.assign(MAX, vector<int>(MAX, -1));
    cout << knapsack(W, wt, val, n) << "\n";
}
