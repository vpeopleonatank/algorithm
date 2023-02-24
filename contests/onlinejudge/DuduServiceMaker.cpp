#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

using namespace std;
int n, m, target;
vector<int> adj[101];
int visited[101];
bool c;

void init() {
  c = false;
  for (int i = 1; i <= n; i++) {
    visited[i] = -1;
  }
}

void DFS(int u) {
  if (c == true) {
    return;
  }
  visited[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    if (target == adj[u][i]) {
      c = true;
      return;
    }
    if (visited[adj[u][i]] == -1) {
      DFS(adj[u][i]);
    }
  }
}

void solve() {
  int t;
  int x, y;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
      cin >> x >> y;
      adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
      if (visited[i] == -1) {
        target = i;
        DFS(i);
        if (c == true) {
          break;
        }
      }
    }
    if (c) {
      cout << "SIM";
    } else {
      cout << "NAO";
    }
    cout << endl;
    adj->clear();
  }
}

int main() {
  // fastio;
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  solve();
  return 0;
}
