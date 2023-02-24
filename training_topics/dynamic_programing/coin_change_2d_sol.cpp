#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  int n, m;
  cin >> n >> m;
  long long c[m];
  for (int i = 0; i < m; ++i) {
    cin >> c[i];
  }
  long long f[m + 1][n + 1];
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[0][i] = 0;
  }
  for (int i = 1; i <= m; ++i) {
    f[i][0] = 1;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = f[i - 1][j];
      if (c[i - 1] <= j) {
        f[i][j] += f[i][j - c[i - 1]];
      }
    }
  }
  cout << f[m][n];

  return 0;
}
