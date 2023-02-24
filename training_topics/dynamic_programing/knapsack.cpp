#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  int N, W;
  cin >> N >> W;
  vector<int> w(N + 1);
  vector<int> v(N + 1);
  vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));
  for (int i = 1; i <= N; ++i) {
    cin >> w[i];
    cin >> v[i];
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= W; j++) {
      dp[i][j] = dp[i - 1][j];
      if (w[i] <= j)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
    }
  }
  cout << dp[N][W];

  return 0;
}
