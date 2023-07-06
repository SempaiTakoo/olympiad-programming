#include <iostream>

using namespace std;

int main() {
    unsigned long long n;
    cin >> n;
    if (n == 0) {
        cout << 1 << '\n';
        return 0;
    }
    unsigned long long fact = 1;
    for (unsigned long long i = 2; i <= n; ++i) {
        fact = (fact * i) % 1000000007;
    }
    cout << fact << '\n';
}