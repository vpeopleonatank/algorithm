// https://www.hackerrank.com/challenges/coin-change/problem
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
  vector<long> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 1; j <= n; j++) {
      if (c[i] <= j) {
        dp[j] += dp[j - c[i]];
      }
    }
  }

  cout << dp[n];
  return 0;
}
