#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)
#define ll long long

using namespace std;
int N, M;
int inf = 1e9;
string a[51];
int dist[51][51][51];
struct coord {
  int x, y, l;
  int distance;
  bool operator<(const coord &c) const { return distance > c.distance; }
};

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int findStep(char c) {
  if (c == 'L') {
    return 0;
  } else if (c == 'U') {
    return 1;
  } else if (c == 'R') {
    return 2;
  }
  return 3;
}

coord S, E;
int len;

void solve() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    for (int j = 0; j < a[i].size(); j++) {
      if (a[i][j] == 'R') {
        S = coord{i, j, 0, 0};
      } else if (a[i][j] == 'E') {
        E = coord{i, j, 0, 0};
      }
    }
  }
  string command;
  cin >> command;
  int len = command.size();
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      for (int k = 0; k <= len; k++) {
        dist[i][j][k] = inf;
      }
    }
  }
  priority_queue<coord> pq;
  pq.push(coord{S.x, S.y, 0, 0});
  dist[S.x][S.y][0] = 0;
  while (!pq.empty()) {
    coord co = pq.top();
    pq.pop();
    int x = co.x;
    int y = co.y;
    int l = co.l;
    int distance = co.distance;
    if (x == E.x && y == E.y) {
      cout << distance;
      return;
    }
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx >= 0 && xx < N && yy >= 0 && yy < M &&
          dist[xx][yy][l] > dist[x][y][l] + 1 && a[xx][yy] != '#') {
        dist[xx][yy][l] = dist[x][y][l] + 1;
        pq.push(coord{xx, yy, l, dist[xx][yy][l]});
      }
    }
    if (l < len) {
      if (dist[x][y][l + 1] > dist[x][y][l] + 1) {
        dist[x][y][l + 1] = dist[x][y][l] + 1;
        pq.push(coord{x, y, l + 1, dist[x][y][l + 1]});
      }
      int pos = findStep(command[l]);
      int xx = x + dx[pos];
      int yy = y + dy[pos];
      if (xx >= 0 && xx < N && yy >= 0 && yy < M && a[xx][yy] != '#') {
        if (dist[xx][yy][l + 1] > dist[x][y][l]) { // bug here
          dist[xx][yy][l + 1] = dist[x][y][l];
          pq.push(coord{xx, yy, l + 1, dist[xx][yy][l + 1]});
        }
      } else if (dist[x][y][l + 1] > dist[x][y][l]) {
        dist[x][y][l + 1] = dist[x][y][l];
        pq.push(coord{x, y, l + 1, dist[x][y][l + 1]});
      }
    }
  }
}

int main() {
  // fastio;
  solve();
  return 0;
}
