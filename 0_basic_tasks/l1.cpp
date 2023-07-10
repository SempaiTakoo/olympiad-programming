#include <bits/stdc++.h>

using ll = int64_t;

#define all(x) (x).begin(), (x).end()

using namespace std;

using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

const ll INF = 1e18;

struct wedge {
    int u, v;
    ll w;

    wedge(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}
};

int main() {
    int n, m, start;
    cin >> n >> m >> start;
    --start;
    vector<wedge> e;
    for (int i = 0; i < m; ++i){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;
        e.emplace_back(u, v, w);
    }
    vector<ll> dp(n, INF);
    dp[start] = 0;
    bool changed = true;
    for (int i = 0; i < n and changed; ++i){
        changed = false;
        for (wedge& elem : e){
            int u = elem.u;
            int v = elem.v;
            ll w = elem.w;
            if (dp[u] + w < dp[v]){
                changed = true;
                dp[v] = dp[u] + w;
            }
        }
    }
    if (changed){
        cout << "Negative cycle\n";
        return 0;
    }
    for (ll elem : dp){
        if (elem < INF){
            cout << elem << ' ';
        } else {
            cout << "inf" << ' ';
        }
    }
    cout << '\n';
    return 0;
}