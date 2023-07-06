#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int curMax = arr[i];
        sum += curMax;
        for (int j = i + 1; j < n; j++) {
            curMax = max(curMax, arr[j]);
            sum += curMax;
        }
    }
    cout << sum << '\n';
    return 0;
}