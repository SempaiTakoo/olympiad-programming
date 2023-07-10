#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;

void dfs(int u, int prev, const graph& g, vector<int>& visited, int& j, vector<int>& vis){
    if (visited[u]){
        return;
    }
    visited[u] = true;
    vis[u] = j;
    j++;
    for (int v : g[u]){
        if (v == prev){
            continue;
        }
        dfs(v, u, g, visited, j, vis);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, start;
    cin >> n >> m >> start;
    --start;
    graph g(n);
    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n, -1);
    int j = 0;
    vector<int> visited(n, 0);
    if (m != 0){
        dfs(start, start, g, visited, j, vis);
    } else {
        vis[start] = 0;
    }
    for (int i : vis){
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}