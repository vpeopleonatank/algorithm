// https://www.spoj.com/problems/ELIS/
#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> dp(n + 1);
  dp[0] = 0;
  int m = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j])
        dp[i] = max(dp[j] + 1, dp[i]);
      if (i == )
    }
    cout << dp[i] << " ";
    m = max(dp[i], m);
  }
  cout << m;
  return 0;
}
