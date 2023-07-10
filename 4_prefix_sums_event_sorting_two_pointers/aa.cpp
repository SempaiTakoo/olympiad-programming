#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < q; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        arr[l - 1] += v;
        if (r < n) {
            arr[r] -= v;
        }
    }
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i-1];
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}