#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define cube(x) (x) * (x) * (x)

void printSolution(vector<string> &l, int p[], int n);

void textJustify(vector<string> &l, int n, int M) {
    // will store the extra spaces if we put words i through j in a line
    int extras[n + 1][n + 1];
    // will store the cost of the extra spaces if we put words i through j in a line
    int lc[n + 1][n + 1];
    // c[i] is the optimal cost of words from 1 to i
    int c[n + 1];
    // this is used for printing the output, the last line starts from p[n] and ends in n
    // the line before that starts from p[p[n]] and ends in p[n] - 1 and so on
    int p[n + 1];
    // compute the extra spaces if we put words i through j in a line
    for (int i = 1; i <= n; i++) {
        extras[i][i] = M - (int)l[i - 1].size();
        for (int j = i + 1; j <= n; j++) {
            extras[i][j] = extras[i][j - 1] - (int)l[j - 1].size() - 1;
        }
    }
    // compute the cost of the extra spaces
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (extras[i][j] < 0) {
                lc[i][j] = INF;
            }
            else if (j == n && extras[i][j] >= 0) {
                lc[i][j] = 0;
            }
            else {
                lc[i][j] = cube(extras[i][j]);
            }
        }
    }
    // compute the optimal cost of words from 1 to i, and the parent of each word
    c[0] = 0;
    for (int j = 1; j <= n; j++) {
        c[j] = INF;
        for (int i = 1; i <= j; i++) {
            if (c[i - 1] != INF && lc[i][j] != INF) {
                if (c[i - 1] + lc[i][j] < c[j]) {
                    c[j] = c[i - 1] + lc[i][j];
                    p[j] = i;
                }
            }
        }
    }
    printSolution(l, p, n);
}

// print the solution based on the parent array
void printSolution(vector<string> &l, int p[], int n) {
    if (p[n] != 1)
        printSolution(l, p, p[n] - 1);
    for (int i = p[n] - 1; i < n - 1; i++) {
        cout << l[i] << " ";
    }
    cout << l[n - 1] << "\n";
}

int main() {
    vector<string> l{
        "aaa", "bb", "cc", "ddddd"
    };
    int n = l.size();
    int M = 6;
    textJustify(l, n, M);
}
