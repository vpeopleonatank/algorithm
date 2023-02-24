#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)
#define ll long long

using namespace std;

int m, n;

const int MAX_N = 100005;
const long long inf = 1e11;

vector<pair<int, long long>> adj[MAX_N];
long long dist[MAX_N];
int trace[MAX_N];
int V, E;

void readInput() {
  cin >> V >> E;
  for (int i = 1; i <= E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  for (int i = 1; i <= V; i++) {
    trace[i] = -1;
  }
}

void Dijkstra(int s) {
  priority_queue < pair<ll, int>, vector<pair<ll, int>>,
                 greater<pair<ll, int>>>
      pq;
  for (int i = 0; i < MAX_N; i++) {
    dist[i] = inf;
  }
  pq.push(make_pair(0, s));
  dist[s] = 0;
  while (!pq.empty()) {
    pair<ll, int> tmp = pq.top();
    pq.pop();
    int u = tmp.second;
    if (tmp.first > dist[u]) {
      continue;
    }
    for (int i = 0; i < adj[u].size(); i++) {
      pair<int, ll> neighbor = adj[u][i];
      int v = neighbor.first;
      ll c = neighbor.second;
      if (dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
        trace[v] = u;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
}

void solve() {
  readInput();
  Dijkstra(1);
  if (trace[V] == -1) {
    cout << -1;
  } else {
    stack<int> s;
    s.push(V);
    int k = V;
    while (trace[k] != 1) {
      s.push(trace[k]);
      k = trace[k];
    }
    s.push(1);
    while (!s.empty()) {
      cout << s.top() << " ";
      s.pop();
    }
  }
}

int main() {
  // fastio;
  solve();
  return 0;
}
