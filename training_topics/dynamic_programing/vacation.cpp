#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

struct d {
  int a, b, c;
};

int main() {
  fastio;
  int n;
  cin >> n;
  vector<d> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].a >> a[i].b >> a[i].c;
  }
  int dp[n][3];
  dp[0][0] = a[0].a;
  dp[0][1] = a[0].b;
  dp[0][2] = a[0].c;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i].a;
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i].b;
    dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + a[i].c;
  }
  n--;
  cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
  
  return 0;
}
