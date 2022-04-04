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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> dp(n);
  dp[0] = 0;
  dp[1] = abs(a[1] - a[0]);
  for (int i = 2; i < n; i++) {
    dp[i] = min(abs(a[i] - a[i - 1]) + dp[i - 1], abs(a[i] - a[i - 2]) + dp[i - 2]);
  }
  cout << dp[n - 1];

  return 0;
}
