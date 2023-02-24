#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1001];
int dist[1001];
int g[1001];
int n;

void DFS(int u) {
  for (int i = 0; i < adj[u].size(); i++) {
    if (dist[adj[u][i]] != -1) {
      dist[adj[u][i]] = dist[u] + 1;
      DFS(adj[u][i]);
    }
  }
}

void solve() {
  cin >> n;
  // int a[n + 1];
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++)
    cin >> g[i];
  for (int i = 2; i <= n; i++)
    dist[i] = -1;
  dist[1] = 0;
  DFS(1);
  int m = 1e9, id;
  for (int i = 0; i < k; i++) {
    if (dist[g[i]] < m) {
      m = dist[g[i]];
      id = g[i];
    } else if (dist[g[i]] == m && id > g[i]) {
      id = g[i];
    }
  }
  cout << id;
}

int main() { solve(); }
