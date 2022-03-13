#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

const int MN = 1e5+1;
int m, n;
vector<int> g[MN];
bool visited[MN];
int first_nodes[MN];

void dfs(int node) {
  visited[node] = true;
  for (int u : g[node]) {
    if (!visited[u])
      dfs(u);
  }
}

int count_components() {
  int count = 0;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      dfs(i);
      first_nodes[count] = i;
      count++;
    }
  }
  return count;
}

int main() {
  fastio;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int num_of_roads = count_components();
  cout << num_of_roads - 1 << endl;
  for (int i = 1; i < num_of_roads; ++i) {
    cout << first_nodes[i] << " " << first_nodes[i - 1] << endl; 
  }
  return 0;
}
