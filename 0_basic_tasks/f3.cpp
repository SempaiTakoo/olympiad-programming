#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

const ll MAX = 1e18;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> cost(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> cost[i];
    }
    vector<ll> dp(n + 1, MAX);
    vector<int> prev(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i - j < 0) {
                break;
            }
            ll jump_j = dp[i - j] + cost[i];
            if (jump_j <= dp[i]) {   
                dp[i] = jump_j;
                prev[i] = i - j;
            }
        }
    }
    vector<int> res;
    int u = n;
    while (u > 0) {
        res.push_back(u);
        u = prev[u];
    }
    res.push_back(0);
    reverse(res.begin(), res.end());

    cout << dp[n] << '\n';
    cout << res.size() << '\n';
    for (int num : res) {
        cout << num << ' ';
    }
    cout << '\n';
}