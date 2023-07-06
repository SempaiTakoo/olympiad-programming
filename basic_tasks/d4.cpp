#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    set<string> words;
    for (int i = 0; i < N; ++i) {
        string cur;
        cin>> cur;
        sort(cur.begin(), cur.end());
        words.insert(cur);
    }
    cout << words.size() << '\n';
}