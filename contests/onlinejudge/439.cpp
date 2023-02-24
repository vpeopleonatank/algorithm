#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int dist[9][9];
int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};

struct coord {
  int x, y;
};

void init() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      dist[i][j] = -1;
    }
  }
}

void BFS(int x1, int y1, int x2, int y2, string start, string end) {
  queue<coord> q;
  q.push((coord){x1, y1});
  dist[x1][y1] = 0;
  while (!q.empty()) {
    coord u = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      coord v = (coord){u.x + dx[i], u.y + dy[i]};
      if (v.x >= 1 && v.x <= 8 && v.y >= 1 && v.y <= 8) {
        if (dist[v.x][v.y] == -1) {
          dist[v.x][v.y] = dist[u.x][u.y] + 1;
          q.push(v);
        }
      }
    }
  }
  cout << "To get from " << start << " to " << end << " takes " << dist[x2][y2] << " knight moves." << endl;
}

void solve() {
  string start, end;
  int x1, y1, x2, y2;
  while (cin >> start >> end) {
    x1 = start[0] - 'a' + 1;
    y1 = start[1] - '0';
    x2 = end[0] - 'a' + 1;
    y2 = end[1] - '0';
    init();
    BFS(x1, y1, x2, y2, start, end);
  }
}

int main() {
  /* fastio; */
  solve();

  return 0;
}
