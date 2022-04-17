#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"
#define ll long long

using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  vector<ll> a(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<ll>> f(n + 1, vector<ll>(n + 1, 0));
  vector<vector<ll>> cost(n + 1, vector<ll>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      for (int k = i; k <= j; k++) {
        cost[i][j] += a[k - 1];
      }
    }
  }
  for (int i = n - 1; i > 0; i--) {
    for (int j = i + 1; j <= n; j++) {
      f[i][j] = 4000000000008;
      for (int k = i; k < j; k++) {
        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
      }
      f[i][j] += cost[i][j];
    }
  }
  cout << f[1][n];
  return 0;
}
