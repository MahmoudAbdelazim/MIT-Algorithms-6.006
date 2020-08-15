#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5; //max number of edges
int v, e; // vertices, edges
vector<vector<int>> adj; //adjacency list
bitset<MAX> visited; // checks if vertix is visited
int d[MAX]; //holds the distances from the source

void bfs(int s) {
    d[s] = 0;
    cout << s << ": " << d[s] << "\n";
    visited[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); // start following the adj list of vertix u (the next level) and pop it off
        q.pop();
        for (int & v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                d[v] = d[u] + 1; // the distance is one plus the distance of the parent vertix
                cout << v << ": " << d[v] << "\n";
                q.push(v); // add them to the tail of the queue follow their adjacency list later (after finishing the current adj list first)
            }
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
    bfs(1);
}
