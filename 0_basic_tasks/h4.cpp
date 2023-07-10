#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int start;
    int end;
};

bool compareSegments(const Segment& a, const Segment& b) {
    if (a.end == b.end) {
        return a.start > b.start;
    } else {
        return a.end < b.end;
    }
}

int maxNonOverlappingSegments(const vector<Segment>& segments) {
    int count = 1;
    int end = segments[0].end;
    for (int i = 1; i < segments.size(); i++) {
        if (segments[i].start >= end) {
            count++;
            end = segments[i].end;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].start >> segments[i].end;
    }
    sort(segments.begin(), segments.end(), compareSegments);
    int count = maxNonOverlappingSegments(segments);
    cout << count << endl;
    return 0;
}