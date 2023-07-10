#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }

    int count = 0;
    for (int i = 0; i < N - 2; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            for (int k = j + 1; k < N; ++k) {
                int a = vec[i], b = vec[j], c = vec[k];
                if ((i != j && i != k && j != k) && (a + b > c && b + c > a && a + c > b)) {
                    ++count;
                }
            }
        }
    }
    cout << count << '\n';
    return 0;
}