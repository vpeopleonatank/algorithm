#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

using namespace std;

int n, m;
vector<int> adj[30005];
int visited[30005];
int cnt, ans;

void init() {
  cnt = 0;
  ans = 0;
  for (int i = 0; i <= n; ++i) {
    visited[i] = -1;
  }
}

void DFS(int u) {
  visited[u] = 1;
  cnt++;
  for (int i = 0; i < adj[u].size(); i++) {
    if (visited[adj[u][i]] == -1) {
      /* cnt++; */
      DFS(adj[u][i]);
    }
  }
}

void solve() {
  int t;
  scanf("%d", &t);
  int k = 1;
  int num =9;
  while (t--) {
    /* cin >> n >> m; */
    scanf("%d %d", &n, &m);
    init();
    /* if (k == num) { */
    /*   cout << n << " " << m << endl; */
    /* } */
    for (int i = 0; i < m; ++i) {
      int x, y;
      /* cin >> x >> y; */
      scanf("%d %d", &x, &y);
      adj[x].push_back(y);
      adj[y].push_back(x);
      /* if (k == num) { */
      /*   cout << x << " " << y << endl; */
      /* } */
    }
    for (int i = 1; i <= n; i++) {
      if (visited[i] == -1) {
        cnt = 0;
        DFS(i);
        if (cnt > ans) {
          ans = cnt;
        }
      }
    }
    cout << ans << endl;
    k++;
  }
}

int main() {
  // fastio;
  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
  solve();


  
  return 0;
}
