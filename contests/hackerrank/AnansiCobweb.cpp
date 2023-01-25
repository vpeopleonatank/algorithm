#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)
#define ll long long

using namespace std;

const int MAX_N = 1e5;
int root[MAX_N];
int ans;
stack<int> l;

int findRoot(int u) { // O(log(N))
  return (root[u] = (root[u] == u ? u : findRoot(root[u])));
}
void unionSet(int u, int v) { // O(log(N))
  int rootu = findRoot(u);
  int rootv = findRoot(v);
  if (rootu != rootv) {
    root[rootu] = rootv;
    ans--;
  }
}
void solve() {
  int n, m, q;
  cin >> n >> m;
  pair<int, int> threads[n];
  ans = n;
  for (int i = 1; i <= n; i++) {
    root[i] = i;
  }
  for (int i = 0; i < m; i++) {
    cin >> threads[i].first >> threads[i].second;
  }
  cin >> q;
  int k[q];
  for (int i = 0; i < q; i++) {
    cin >> k[i];
  }
  for (int i = 0; i < m; i++) {
    bool c = false;
    for (int j = 0; j < q; j++) {
      if (k[j] == i + 1) {
        c = true;
        break;
      }
    }
    if (!c) {
      unionSet(threads[i].first, threads[i].second);
    }
  }
  for (int i = q - 1; i >= 0; i--) {
    l.push(ans);
    unionSet(threads[k[i] - 1].first, threads[k[i] - 1].second);

  }
  while (!l.empty()) {
    cout << l.top() << " ";
    l.pop();
  }
}

int main() {
  // fastio;
  solve();
  return 0;
}
