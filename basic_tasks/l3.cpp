#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> d(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> d[i][j];
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << d[i][j] << " ";
    }
    cout << '\n';
  }  
  return 0;
}