// https://www.spoj.com/problems/MBLAST/
#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  string a, b;
  cin >> a >> b;
  int k;
  cin >> k;
  int dp[a.length() + 1][b.length() + 1];
  for (int i = 0; i <= a.length(); ++i) {
    dp[i][0] = k * i;
  }
  for (int i = 0; i <= b.length(); ++i) {
    dp[0][i] = k * i;
  }
  for (int i = 1; i <= a.length(); ++i) {
    for (int j = 1; j <= b.length(); j++) {
      dp[i][j] = min(dp[i - 1][j] + k, min(dp[i][j - 1] + k, dp[i - 1][j - 1] + abs(a[i - 1] - b[j - 1])));
    }
  }
  cout << dp[a.length()][b.length()];
  return 0;
}
