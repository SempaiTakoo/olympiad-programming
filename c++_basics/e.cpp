#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    string s;
    cin >> s;
    int count = 0;
    for (ull i = 0; i < s.size(); ++i) {
        char cur = s[i];
        if (cur == '0' or cur == '4' or cur == '6' or cur == '9') {
            ++count;
        } else if (cur == '8') {
            count += 2;
        }
    }
    cout << count << '\n';
}