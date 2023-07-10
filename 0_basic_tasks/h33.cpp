#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    int x;
    int type;
    int index;
    
    Event(int x, int type, int index) : x(x), type(type), index(index) {}
};

bool sortByX(const Event& e1, const Event& e2) {
    if (e1.x != e2.x) {
        return e1.x < e2.x;
    }
    return e1.type < e2.type;
}

int main() {
    int N;
    cin >> N;
    vector<Event> events;
    for (int i = 0; i < N; i++) {
        int li, ri;
        cin >> li >> ri;
        events.push_back(Event(li, 0, i));
        events.push_back(Event(ri, 1, i));
    }
    sort(events.begin(), events.end(), sortByX);
    int maxPoints = 0;
    int maxPoint = 0;
    int currentPoints = 0;
    vector<int> segmentTree(4*N, 0);
    for (const auto& event : events) {
        if (event.type == 0) {
            currentPoints++;
            segmentTree[event.index]++;
        } else {
            currentPoints--;
            segmentTree[event.index]--;
        }
        if (currentPoints > maxPoints) {
            maxPoints = currentPoints;
            maxPoint = event.x;
        } else if (currentPoints == maxPoints && event.x < maxPoint) {
            maxPoint = event.x;
        }
    }
    cout << maxPoints << ' ' << maxPoint << '\n';
    return 0;
}