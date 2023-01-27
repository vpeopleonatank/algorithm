#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)
#define ll long long

using namespace std;

struct edge {
  int u, v, w;
};
const int MAX_M = 1e5;

edge listEdges[MAX_M];
int root[MAX_M];

int findRoot(int u) {
  return (root[u] = (root[u] == u ? u : findRoot(root[u])));
}

bool compare_edge(const edge &e1, const edge &e2) { return e2.w >= e1.w; }

void solve() {
  int T;
  cin >> T;
  for (int k = 1; k <= T; k++) {
    int N, M, A, ans, res = 0;
    cin >> N >> M >> A;
    ans = N;
    for (int i = 1; i <= N; i++) {
      root[i] = i;
    }
    for (int i = 0; i < M; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      listEdges[i] = (edge){u, v, w};
    }
    sort(listEdges, listEdges + M, compare_edge);
    for (int i = 0; i < M; i++) {
      int u = findRoot(listEdges[i].u);
      int v = findRoot(listEdges[i].v);
      int w = listEdges[i].w;
      if (u != v) {
        if (w < A) {
          root[u] = v;
          ans--;
          res += listEdges[i].w;
        }
      }
    }
    cout << "Case " << k << ": " << res + ans * A << " " << ans << endl;
  }
}

int main() {
  // fastio;
  solve();
  return 0;
}
