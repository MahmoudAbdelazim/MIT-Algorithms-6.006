#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6; // max number of vertices
int v, e; // vertices and edges
bitset<MAX> visited; // to identify visited vertices
vector<vector<int>> adj; // adjacency list

void dfs_visit(int s) { // does DFS on a certain vertix
    visited[s] = 1;
    cout << s << " ";
    for (int &i: adj[s]) {
        if (!visited[i]) {
            dfs_visit(i);
        }
    }
}

vector<vector<int>> transpose() {
    vector<vector<int>> tmp(v + 1);
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            tmp[adj[i][j]].push_back(i);
        }
    }
    return tmp;
}

void dfs_fill_order(int s, stack<int> &Stack) { // does DFS on a certain vertix
    visited[s] = 1;
    for (int &i: adj[s]) {
        if (!visited[i]) {
            dfs_fill_order(i, Stack);
        }
    }
    Stack.push(s);
}

void dfs(stack<int> &Stack) { // does DFS_Visit on all non-visited vertices in the graph
    visited.reset();
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            dfs_fill_order(i, Stack);
        }
    }
}

void stronglyConnectedComponents() {
    stack<int> Stack;
    dfs(Stack);
    adj = transpose();
    visited.reset();
    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();
        if (!visited[v]) {
            dfs_visit(v);
            cout << "\n";
        }
    }
}

int main() {
    v = 8, e = 14;
    adj = { // 1-indexed
            {},
            {2},
            {3, 4, 6},
            {1, 4},
            {5},
            {4, 8},
            {5, 7},
            {6, 8},
            {8}
    };
    stronglyConnectedComponents();
}
