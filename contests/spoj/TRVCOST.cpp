#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

using namespace std;

int m, n;

const int MAX_N = 100005;
const int inf = 1e9;
int E, S, Q, u;

vector<pair<int, int>> adj[MAX_N];
vector<int> target;
int dist[MAX_N];

void readInput() {
  cin >> E;
  for (int i = 1; i <= E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  cin >> S >> Q;

  for (int i = 0; i < Q; i++) {
    cin >> u;
    target.push_back(u);
  }
}

void Dijkstra(int s) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  for (int i = 0; i < MAX_N; i++) {
    dist[i] = inf;
  }
  pq.push(make_pair(0, s));
  dist[s] = 0;
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
}

void solve() {
  readInput();
  Dijkstra(S);
  for (int i = 0; i < Q; i++) {
    if (dist[target[i]] == inf) {
      cout << "NO PATH";
    } else
      cout << dist[target[i]];
    cout << endl;
  }
}

int main() {
  // fastio;
  solve();
  return 0;
}
