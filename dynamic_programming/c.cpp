#include <iostream>
#include <vector>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        dp[x][y] = 0;
    }
    if ((n == 0 || m == 0) && k > 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] != 0) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
