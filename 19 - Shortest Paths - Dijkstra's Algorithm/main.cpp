#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF (int)1e9

vector<vii> adj;
vi dist;
int V, E;

void dijkstra(int s) {
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq; // Min Heap
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u])
            continue;
        for (auto v: adj[u]) {
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }
}

int main() {
    cin >> V >> E;
    adj.resize(V);
    dist.assign(V, INF);
    for (int i = 0; i < E; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(y, w));
    }
    int s;
    cin >> s;
    dijkstra(s);
    for (int i = 0; i < V; i++) {
        cout << dist[i] << " ";
    }
}
