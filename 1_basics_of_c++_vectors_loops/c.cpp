#include <iostream>

using namespace std;
using ull = unsigned long long int;

int main() {
    ull N;
    cin >> N;
    if (N == 0 or N == 1) {
        cout << N << '\n';
        return 0;
    }
    ull first = 0, second = 1, third, order = 2;
    while (1) {
        third = first + second;
        if (third == N) {
            cout << order << '\n';
            return 0;
        }
        if (third > N) {
            cout << -1 << '\n';
            return 0;
        }
        ++order;
        first = second;
        second = third;
    }
}