#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;
using pii = std::pair<int, int>;
using graph = vector<vector<int>>;

const int INF = 1e9;

void bfs(const graph& g, int u, vector<int>& d, vector<int>& prev){
    int n = g.size();
    d.assign(n, INF);
    prev.assign(n, -1);
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        u = q.front();
        q.pop();
        for (int v : g[u]){
            if (d[v] == INF){
                prev[v] = u;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
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
    vector<int> d, prev;
    bfs(g, start, d, prev);
    for (int elem : d){
        cout << (elem == INF ? -1 : elem) << ' ';
    }
    cout << endl;
}