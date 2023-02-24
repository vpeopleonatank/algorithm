#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)
#define ll long long

using namespace std;

const int MAX_N = 100005;
const int INF = 1000000007;
int V, E;
vector<pair<int, int>> adj[MAX_N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int weight[MAX_N];
bool mark[MAX_N];

void prim(int source) {
  for (int i = 1; i <= V; i++) {
    weight[i] = INF;
  }
  weight[source] = 0;
  pq.push(make_pair(0, source));
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
  cout << res;
}

void solve() {
  cin >> V >> E;
  for (int i = 1; i <= E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  prim(1);
}

int main() {
  // fastio;
  solve();
  return 0;
}
