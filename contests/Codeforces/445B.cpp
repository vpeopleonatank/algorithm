#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)
#define ll long long

using namespace std;

const int MAX_N = 100005;
int root[MAX_N];

int findRoot(int u) { // O(log(N))
  return (root[u] = (root[u] == u ? u : findRoot(root[u])));
}
void unionSet(int u, int v) { // O(log(N))
  int rootu = findRoot(u);
  int rootv = findRoot(v);
  if (rootu != rootv) {
    root[rootu] = rootv;
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    root[i] = i;
  }
  pair<int, int> p[m];
  for (int i = 0; i < m; i++) {
    cin >> p[i].first;
    cin >> p[i].second;
  }
  ll ans = 1;
  for (int i = 0; i < m; i++) {
    int rootu = findRoot(p[i].first);
    int rootv = findRoot(p[i].second);
    if (rootu != rootv) {
      ans *= 2;
      root[rootu] = rootv;
    }
  }
  cout << ans;
}

int main() {
  // fastio;
  solve();
  return 0;
}
