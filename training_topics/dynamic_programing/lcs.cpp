#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  string x, y;
  cin >> x >> y;
  vector<vector<int>> dp(x.length() + 1, vector<int>(y.length() + 1, 0));
  for (int i = 0; i < x.length(); ++i) {
    dp[i][0] = 0;
  }
  for (int i = 0; i < y.length(); ++i) {
    dp[0][i] = 0;
  }
  for (int i = 1; i <= x.length(); ++i) {
    for (int j = 1; j <= y.length(); j++) {
      if (x[i - 1] == y[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << dp[x.length()][y.length()];
  return 0;
}
