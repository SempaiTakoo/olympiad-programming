#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

#define all(x) x.begin(), x.end()

struct event { 
    int pos, val;

    event() = default;

    event(int _pos, int _val) : pos(_pos), val(_val) {}
};

bool comp(const event& a, const event& b) {
    if (a.pos != b.pos) {
        return a.pos < b.pos;
    } else {
        return a.val < b.val;
    }
}

int main() {
    int n;
    cin >> n;
    vector<event> e;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        e.emplace_back(l, 1);
        e.emplace_back(r + 1, -1);
    }
    sort(all(e), comp);
    pii res(-1, -1);
    int ans = 0;
    int cnt = 0;
    int last_pos = -1;
    for (event elem : e) {
        cnt += elem.val;
        if (cnt > 0 && last_pos == -1) {    
            last_pos = elem.pos;
        }
        if (cnt == 0) {
            int l = last_pos;
            int r = elem.pos - 1;
            if (r - l + 1 > ans) {
                ans = r - l + 1;
                res = {l, r};
            }
            last_pos = -1;
        }
    }
    cout << cnt << ' ' << res.first << '\n';
}