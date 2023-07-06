#include <iostream>
#include <vector>

using namespace std;
using ll = long long int;

const ll MAX = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i - j < 0) {
                break;
            }
            dp[i] = (dp[i] + dp[i - j]) % MAX;
        }
    }
    cout << dp[n] << '\n';
}