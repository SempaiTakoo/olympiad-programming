#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e18;

struct wedge {
    int u, v;
    int width;
};

vector<int> dijkstra(const vector<vector<wedge>>& graph, int s) {
    int n = graph.size();
    vector<int> maxWeight(n, -1);
    maxWeight[s] = INF;
    priority_queue<pair<int, int>> pq;
    pq.push({INF, s});
    while (!pq.empty()) {
        int curWidth = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (curWidth < maxWeight[u]) {
            continue;
        }
        for (const wedge& edge : graph[u]) {
            int v = edge.v;
            int width = min(curWidth, edge.width);
            if (width > maxWeight[v]) {
                maxWeight[v] = width;
                pq.push({width, v});
            }
        }
    }
    return maxWeight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    --s;
    vector<vector<wedge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        graph[u].push_back({u, v, w});
        graph[v].push_back({v, u, w});
    }
    vector<int> maxWeight = dijkstra(graph, s);
    for (int i = 0; i < n; i++) {
        if (i == s) {
            cout << "-1 ";
        } else if (maxWeight[i] == -1){
            cout << "0 ";
        } else { 
            cout << maxWeight[i] << ' ';
        }
    }
    cout << '\n';
    return 0;
}