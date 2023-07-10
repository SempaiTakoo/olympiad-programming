#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ull = unsigned long long int; 

const ull MAX_NUM = 10e9 + 7;

void print_vec(vector<int>& vec, int size) {
    for (int i = 0; i < size; ++i) {
        cout << vec[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int l, r;
    cin >> l >> r;
    vector<int> dp(r, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << i << ' ' << j << ' ' << i % j << ' ' << i / j << '\n';
            if (i % j == 0) {
                dp[i] += dp[i / j];
            }
        }
    }
    print_vec(dp, r);
}