#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ull = unsigned long long int; 

const ull MAX_NUM = 10e9 + 7;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> vec(m);
    for (int i = 0; i < m; ++i) {
        cin >> vec[i];
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i <= n; ++i) {
        if (find(vec.begin(), vec.end(), i) != vec.end()) {
                continue;
        }
        for (int j = 1; j <= k; ++j) {
            if (i - j < 0)
                break;
            dp[i] = (dp[i] + dp[i - j]) % MAX_NUM;
        }
    }
    cout << dp[n] << '\n';
}