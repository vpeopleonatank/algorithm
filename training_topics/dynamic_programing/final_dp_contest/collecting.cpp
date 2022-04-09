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
  ll c[n];
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  vector<ll> f(n + 1, 0);
  ll m = 0;
  f[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (i <= 2) {
      f[i] += f[i - 1] + c[i - 1];
    } else {
      ll cur = c[i - 1], p1 = c[i - 2];
      f[i] = max(f[i - 2] + cur, max(f[i - 3] + cur + p1, f[i - 1]));
    }
    m = max((ll)f[i], m);
  }
  cout << m;
  return 0;
}
