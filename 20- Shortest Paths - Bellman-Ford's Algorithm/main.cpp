#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF (int)1e9

vector<vii> adj;
vi dist;
int V, E;

void bellmanFord(int s) {
    dist.assign(V, INF);
    dist[s] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (ii v: adj[u]) {
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
            }
        }
    }
    // This part is for detecting negative cycles, usually not written in problem solving
    for (int u = 0; u < V; u++) {
        for (ii v: adj[u]) {
            if (dist[u] + v.second < dist[v.first]) {
                // report negative cycle;
            }
        }
    }
}


int main() {
    cin >> V >> E;
    adj.resize(V);
    for (int i = 0; i < E; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(y, w));
    }
    int s, d;
    cin >> s >> d;
    bellmanFord(s);
    cout << dist[d] << "\n";
}
