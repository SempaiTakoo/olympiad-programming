#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll total = 0;
    ll cur;
    for (int i = 0; i < n; ++i) {
        cin >> cur;
        total += cur;
    }
    cout << total << '\n';
    return 0;
}