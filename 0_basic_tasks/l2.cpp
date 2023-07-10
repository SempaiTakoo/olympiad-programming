#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

const ll INF = 1e18;

void dijkstra(vector<vector<pair<ll, ll>>>& graph, vector<ll>& dist, vector<ll>& prev) {
    ll n = graph.size();
    dist.assign(n, INF);
    prev.assign(n, -1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
        for (auto edge : graph[u]) {
            ll v = edge.first;
            ll weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

vector<ll> reconstructPath(vector<ll>& prev) {
    vector<ll> path;
    ll curr = prev.size() - 1;
    if (prev[curr] == -1) {
        return path;
    }
    while (curr != -1) {
        path.push_back(curr + 1);
        curr = prev[curr];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
    }
    vector<ll> dist, prev;
    dijkstra(graph, dist, prev);
    vector<ll> path = reconstructPath(prev);
    if (path.empty()) {
        cout << -1 << endl;
    } else {
        for (ll vertex : path) {
            cout << vertex << ' ';
        }
        cout << endl;
    }   
    return 0;
}