#include <bits/stdc++.h>

using namespace std;
#define MAX 1000
vector<vector<int>> dp;

int editDistance(string &str1, string &str2, int m, int n) {
    if (m == 0) return n; // if str1 is empty, then the cost is inserting all str2
    if (n == 0) return m; // if str2 is empty, then the cost is inserting all str1

    int option1 = dp[m - 1][n - 1]; // replace
    int option2 = dp[m][n - 1]; // insert
    int option3 = dp[m - 1][n]; // remove

    if (str1[m - 1] == str2[n - 1]) {
        if (option1 != -1) {
            return dp[m][n] = option1;
        } else {
            return dp[m][n] = dp[m - 1][n - 1] = editDistance(str1, str2, m - 1, n - 1);
        }
    }
    if (option1 == -1) {
        option1 = dp[m - 1][n - 1] = editDistance(str1, str2, m - 1, n - 1);
    }
    if (option2 == -1) {
        option2 = dp[m][n - 1] = editDistance(str1, str2, m, n - 1);
    }
    if (option3 == -1) {
        option3 = dp[m - 1][n] = editDistance(str1, str2, m - 1, n);
    }
    // try the three options, insert, remove or replace the last character of str1 with the last character of str2
    return dp[m][n] = 1 + min(option1, min(option2, option3));
}

int editDistanceTabulization(string &str1, string &str2, int m, int n) {
    int table[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) table[i][j] = j;
            else if (j == 0) table[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                table[i][j] = table[i - 1][j - 1];
            else
                table[i][j] = 1 + min(table[i][j - 1], min(
                        table[i - 1][j],
                        table[i - 1][j - 1]));
        }
    }
    return table[m][n];
}

int main() {
    string str1 = "sunday", str2 = "saturday";
    dp.assign(MAX, vector<int>(MAX, -1));
    cout << editDistance(str1, str2, str1.size(), str2.size());
}
