#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)
#define ll long long

using namespace std;
const int MAX_N = 10005;
const int INF = 1000000007;
int V, E, L, S, N_S;
vector<pair<int, int>> adj[MAX_N];
int start_S[MAX_N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int weight[MAX_N];
bool mark[MAX_N];

void prim() {
  for (int i = 0; i < N_S; i++) {
    weight[start_S[i]] = 0;
    pq.push(make_pair(0, start_S[i]));
  }
  while (!pq.empty()) {
    pair<int, int> minTop = pq.top();
    pq.pop();
    int W = minTop.first;
    int u = minTop.second;
    if (weight[u] < W) {
      continue;
    }
    mark[u] = true;
    for (int i = 0; i < (int)adj[u].size(); i++) {
      pair<int, int> prAdj = adj[u][i];
      int v = prAdj.first;
      int w = prAdj.second;
      if (mark[v] == true) {
        continue;
      }
      if (weight[v] > w) {
        weight[v] = w;
        pq.push(make_pair(weight[v], v));
      }
    }
  }
  long long res = 0;
  for (int i = 1; i <= V; i++) {
    res += 1LL * weight[i];
  }
  cout << res << endl;
}

void solve() {
  int T;
  cin >> T;
  while (T--) {
    cin >> V >> E >> L >> N_S;
    for (int i = 0; i < N_S; i++) {
      cin >> start_S[i];
    }
    for (int i = 1; i <= V; i++) {
      adj[i].clear();
      weight[i] = INF;
      mark[i] = false;
    }
    for (int i = 1; i <= E; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      w += L;
      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
    }
    prim();
  }
}

int main() {
  // fastio;
  solve();
  return 0;
}
