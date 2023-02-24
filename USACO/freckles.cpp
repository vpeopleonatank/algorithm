#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)
#define ll long long

using namespace std;

struct coord {
  float x, y;
};

const int MAX_N = 10005;
const float INF = 1000000007.;
int V, E;
vector<pair<int, float>> adj[MAX_N];
priority_queue<pair<float, int>, vector<pair<float, int>>,
               greater<pair<float, int>>>
    pq;
float weight[MAX_N];
int vertex[MAX_N];
bool mark[MAX_N];

void prim(int source) {
  for (int i = 1; i <= V; i++) {
    weight[i] = (float) INF;
    mark[i] = false;
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
      pair<int, float> prAdj = adj[u][i];
      int v = prAdj.first;
      float w = prAdj.second;
      if (mark[v] == true) {
        continue;
      }
      if (weight[v] > w) {
        weight[v] = w;
        vertex[v] = u;
        pq.push(make_pair(weight[v], v));
      }
    }
  }
  double res = 0;
  for (int i = 1; i <= V; i++) {
    res += weight[i];
  }
  cout << fixed << setprecision(2) << res << endl;
}

void solve() {
  int T;
  cin >> T;
  while (T--) {
    cin >> V;
    vector<coord> v;
    float x, y;
    for (int i = 0; i < V; i++) {
      cin >> x >> y;
      v.push_back(coord{x, y});
    }
    for (int i = 1; i <= V; i++) {
      for (int j = i + 1; j <= V; j++) {
        if (i == j) {
          continue;
        }
        float w = sqrt(pow(v[i - 1].x - v[j - 1].x, 2) +
                       pow(v[i - 1].y - v[j - 1].y, 2));
        adj[i].push_back(make_pair(j, w));
        adj[j].push_back(make_pair(i, w));
      }
    }
    prim(1);
  }
}

int main() {
  // fastio;
  solve();
  return 0;
}
