#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int>& vec, int l, int r) {
    for (; l < r; ++l, --r) {
        int temp = vec[l];
        vec[l] = vec[r];
        vec[r] = temp;
    }
}

void print_vec(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n; ++i) {
        cout << vec[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int l, r;
    while (cin >> l >> r) {
        if (l == 0 and r == 0)
            break;
        reverse(vec, l - 1, r - 1);
    }
    print_vec(vec);
}