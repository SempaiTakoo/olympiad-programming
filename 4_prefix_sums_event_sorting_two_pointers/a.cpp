#include <iostream>
#include <vector>

using namespace std;
using ll = long long int;

void print_vec(vector<ll>& vec, int size) {
    for (int i = 0; i < size; ++i) {
        cout << vec[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> vec(N, 0);
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        int l, r, v;
        cin >> l >> r >> v;
        prefix[l] += v;
        prefix[r + 1] -= v;
    }
    for (int i = 0; i <= N; ++i) {
        prefix[i + 1] = prefix[i] + vec[i];
    }
    print_vec(prefix, N + 1);
    return 0;
}