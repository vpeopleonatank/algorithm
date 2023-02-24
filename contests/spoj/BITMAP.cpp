#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

struct coord {
  int x, y;
};

const int MAX = 185;
int dist[MAX][MAX];
int a[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int r, c;

void init() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      dist[i][j] = -1;
    }
  }
}

void BFS(queue<coord> Q) {
  while (!Q.empty()) {
    coord u = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      coord v{u.x + dx[i], u.y + dy[i]};
      if (v.x >= 0 && v.x < c && v.y >= 0 && v.y < r &&
          dist[v.x][v.y] == -1) {
        dist[v.x][v.y] = dist[u.x][u.y] + 1;
        Q.push(v);
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
    cin >> r >> c;

    queue<coord> Q;
    init();
    for (int i = 0; i < r; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < c; j++) {
        a[i][j] = s[j] - '0';
        if (a[i][j] == 1) {
          Q.push(coord{i, j});
          dist[i][j] = 0;
        }
      }
    }
    BFS(Q);
  }
}

int main() {
  fastio;
  solve();
  return 0;
}
