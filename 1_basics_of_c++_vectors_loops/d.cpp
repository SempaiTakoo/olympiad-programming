#include <iostream>
#include <deque>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        deque<int> res;
        res.push_front(n / 5000);
        n %= 5000;
        res.push_front(n / 1000);
        n %= 1000;
        res.push_front(n / 500);
        n %= 500;
        res.push_front(n / 200);
        n %= 200;
        res.push_front(n / 100);
        for (int i = 0; i < 5; ++i) {
            cout << res.at(i) << ' ';
        }
        cout << '\n';
    }
}