#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

class team {
    public:
        string name;
        int s;
        int p;
};

bool cmpTeams(team t1, team t2) {
    if (t1.s > t2.s) return true;
    if (t1.s < t2.s) return false;
    if (t1.p < t2.p) return true;
    if (t1.p > t2.p) return false;
    if (t1.name < t2.name) return true;
    else return false;
}

int main() {
    int N;
    cin >> N;
    vector<team> teams(N);
    for (int i = 0; i < N; ++i) {
        cin >> teams[i].name >> teams[i].s >> teams[i].p;
    }
    stable_sort(teams.begin(), teams.end(), cmpTeams);
    for (int i = 0; i < N; ++i) {
        cout << teams[i].name << '\n';
    }
}