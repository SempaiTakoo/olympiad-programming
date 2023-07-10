#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MIN = -2147483648;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> sections;
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        sections.push_back(make_pair(l, r));
    }
    sort(sections.begin(), sections.end());
    int count = 0;
    int current_end = MIN;
    for (int i = 0; i < N; i++) {
        if (sections[i].first > current_end) {
            count += (sections[i].second - sections[i].first + 1);
            current_end = sections[i].second;
        } else if (sections[i].second > current_end) {
            count += (sections[i].second - current_end);
            current_end = sections[i].second;
        }
    }
    cout << count << '\n';
    return 0;
}