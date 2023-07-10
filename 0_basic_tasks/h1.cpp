#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + a[i - 1];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << p[r] - p[l - 1] << '\n';
    }
}