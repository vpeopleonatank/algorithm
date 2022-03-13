#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

const int MN = 1e5 + 1;
bool vis[MN], bad, group[MN];
int n, m;
vector<int> g[MN];

void dfs(int n, bool c = 0) {
  vis[n] = 1;
  group[n] = c;
  for (int u : g[n]) {
    if (vis[u]) {
      if (group[u] == c) {
        bad = 1;
        return;
      }
    } else {
      dfs(u, !c);
    }
  }
}

int main() {
  fastio;
  cin >> n >> m;
  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; !bad && i <= n; ++i) {
    if (!vis[i])
      dfs(i);
  }
  if (bad)
    cout << "IMPOSSIBLE";
  else {
    for (int i = 1; i <= n; i++) {
      cout << group[i] + 1 << " ";
    }
  }
  
  return 0;
}
