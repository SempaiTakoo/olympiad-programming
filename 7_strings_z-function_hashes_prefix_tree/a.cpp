#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> z_func(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    string real, dream;
    cin >> real >> dream;
    string concatenated = dream + "#" + real + real;
    vector<int> z = z_func(concatenated);
    int dreamLen = dream.length();
    int realLen = real.length();
    for (int i = 0; i < realLen; i++) {
        if (z[dreamLen + 1 + i] == dreamLen) {
            cout << (realLen - i) % realLen << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}