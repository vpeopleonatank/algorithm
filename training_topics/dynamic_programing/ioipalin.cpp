#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
  for (int i = n - 1; i > 0; i--) {
    for (int j = i + 1; j <= n; j++) {
      if (s[i - 1] == s[j - 1]) {
        f[i][j] = f[i + 1][j - 1];
      } else {
        f[i][j] = min(f[i][j - 1], f[i + 1][j]) + 1;
      }
    }
  }
  cout << f[1][n];
  return 0;
}
