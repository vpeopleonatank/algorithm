#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

void solve() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0, sm = 0, r = 0;
  for (int i = 0; i < n; i++) {
    while (sm + a[r] <= t && r < n) {
      sm += a[r];
      r++;
    }
    ans = max(ans, r - i);
    sm -= a[i];
  }
  cout << ans;
}

int main() {
  fastio;
  solve();
  return 0;
}
