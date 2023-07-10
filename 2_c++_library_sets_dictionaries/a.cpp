#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    bool isFirst = true;
    int first, cur, delta = 0, count = 0;
    for (int i = 0; i < N; ++i) {
        cur = vec[i];
        if (isFirst) {
            first = cur;
            ++delta;
            isFirst = false;
            continue;
        }
        if (cur != first + delta) {
            cout << "Scammed\n";
            return 0;
        }
        ++delta;
        ++count;
    }
    if ((cur == first + N - 1) and (count == N - 1)) {
        cout << "Deck looks good\n";
    } else {
        cout << "Scammed\n";
    }
    return 0;
}