#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;

bool dfs(int u, int v) {
    visited[u] = true;
    path.push_back(u);
    if (u == v) {
        return true;
    }
    for (int i = 0; i < adj[u].size(); i++) {
        int next = adj[u][i];
        if (!visited[next]) {
            if (dfs(next, v)) {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

int main() {
    int n, m, u, v;
    cin >> n >> m >> u >> v;
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (dfs(u, v)) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}