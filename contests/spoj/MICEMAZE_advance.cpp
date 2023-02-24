#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

using namespace std;

int m, n;

const int MAX_N = 105;
const int inf = 1e9;
int N, E, T, M;

vector<pair<int, int>> adj[MAX_N];
int dist[MAX_N];
void init() {
  for (int i = 1; i <= N; i++) {
    dist[i] = inf;
  }
}

void readInput() {
  cin >> N >> E >> T >> M;
  for (int i = 1; i <= M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[v].push_back(make_pair(u, w));
  }
}

void Dijkstra() {
  init();
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push(make_pair(0, E));
  dist[E] = 0;
  while (!pq.empty()) {
    pair<int, int> tmp = pq.top();
    pq.pop();
    int u = tmp.second;
    if (tmp.first > dist[u]) {
      continue;
    }
    for (int i = 0; i < adj[u].size(); i++) {
      pair<int, int> neighbor = adj[u][i];
      int v = neighbor.first;
      int c = neighbor.second;
      if (dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
  int c = 0;
  for (int i = 1; i <= N; ++i) {
    if (dist[i] <= T) {
      c++;
    }
  }
  cout << c;
}

void solve() {
  readInput();
  Dijkstra();
}

int main() {
  // fastio;
  solve();
  return 0;
}
