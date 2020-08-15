#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6; // max number of vertices
int v, e; // vertices and edges
bitset<MAX> visited; // to identify visited vertices
int d[MAX]; // the starting time of visiting a vertix
int f[MAX]; // the finishing time of visiting a vertix
vector<vector<int>> adj; // adjacency list
int Time = 0; // to keep track of time stamps
list<int> sorted;

void dfs_visit(int s) { // does DFS on a certain vertix
    ++Time;
    d[s] = Time;
    visited[s] = 1;
    for (int &i: adj[s]) {
        if (!visited[i]) {
            dfs_visit(i);
        }
    }
    ++Time;
    f[s] = Time;
    sorted.push_front(s); //add this vertix at the front as it finishes
}

void topologicalSort() { // does DFS_Visit on all non-visited vertices in the graph
    Time = 0;
    visited.reset();
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            dfs_visit(i);
        }
    }
}

int main() {
    //graph must be a directed acyclic graph (DAG)
    v = 5, e = 4;
    adj = {
            {},
            {2},
            {3},
            {5},
            {3},
            {}
    };
    memset(d, -1, sizeof(d));
    memset(f, -1, sizeof(f));
    topologicalSort();
    for (auto &i: sorted)
        cout << i << " ";
    cout << "\n";
}
