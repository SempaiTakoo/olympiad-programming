#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    if (N == 1) {
        return 0;
    }

    multiset<ll> clans;
    for (ll i = 0; i < N; ++i) {
        ll cur;
        cin >> cur;
        clans.insert(cur);
    }
    while (clans.size() != 1) {
        ll a = *clans.begin();
        clans.erase(clans.begin());
        ll b = *clans.begin();
        clans.erase(clans.begin());
        cout << a << ' ' << b << '\n';
        clans.insert(a + b);
    }
    return 0;
}