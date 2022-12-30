#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define ll long long

using namespace std;

const int MAX_N = 100005;
int root[MAX_N];
vector<pair<int, int>> vertices;
int ans;

int findRoot(int u) { // O(log(N))
  return (root[u] = (root[u] == u ? u : findRoot(root[u])));
}
void unionSet(int u, int v) { // O(log(N))
  int rootu = findRoot(u);
  int rootv = findRoot(v);
  if (rootu != rootv) {
    root[rootu] = rootv;
    ans--;
  }
}

void solve() {
  int n;
  cin >> n;
  ans = n;
  for (int i = 0; i <= n; i++) {
    root[i] = i;
  }
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    vertices.push_back(make_pair(x, y));
  }
  for(int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (vertices[i].first == vertices[j].first || vertices[i].second == vertices[j].second ) {
        unionSet(i, j);
      }
    }
  }
  cout << ans - 1;

}

int main() {
  //fastio;
  solve();
  return 0;
}
