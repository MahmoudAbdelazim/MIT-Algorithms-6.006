#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6; // max number of vertices
int v, e; // vertices and edges
bitset<MAX> visited; // to identify visited vertices
int d[MAX]; // the starting time of visiting a vertix
int f[MAX]; // the finishing time of visiting a vertix
vector<vector<int>> adj; // adjacency list
int Time = 0; // to keep track of time stamps

void dfs_visit(int s) { // does DFS on a certain vertix
    ++Time;
    d[s] = Time;
    cout << s << " start: " << d[s] << "\n";
    visited[s] = 1;
    for (int &i: adj[s]) {
        if (!visited[i]) {
            dfs_visit(i);
        }
    }
    ++Time;
    f[s] = Time;
    cout << s << " finish: " << f[s] << "\n";
}

void dfs() { // does DFS_Visit on all non-visited vertices in the graph
    Time = 0;
    visited.reset();
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            dfs_visit(i);
        }
    }
}

int main() {
    // graph is undirected and unweighted
    v = 8, e = 10;
    adj = { // 1-indexed
            {},
            {2, 3},
            {1, 4},
            {1, 5, 6},
            {2},
            {3, 6, 8},
            {3, 5, 7, 8},
            {6, 8},
            {5, 6, 7}
    };
    memset(d, -1, sizeof(d));
    memset(f, -1, sizeof(f));
    dfs();
}
