#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string big, tiny;
    cin >> big >> tiny;
    
    int count = 0;
    size_t index = big.find(tiny);
    while (index != string::npos) {
        ++count;
        index = big.find(tiny, index + 1);
    }
    cout << count << '\n';
    return 0;
}