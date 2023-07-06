#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    set<int> elems;
    for (int i = 0; i < N; ++i) {
        int cur;
        cin >> cur;
        elems.insert(cur);
    }
    cout << elems.size() << '\n';
}