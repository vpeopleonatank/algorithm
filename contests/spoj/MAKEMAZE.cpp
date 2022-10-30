#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

using namespace std;

int t, m, n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string l[21];
bool ch;
bool visited[21][21];
vector<pair<int, int>> p;

bool checkOnBorder(int i, int j) {
  if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
    return true;
  return false;
}

void init() {
  ch = false;
  p.clear();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      visited[i][j] = false;
    }
  }
}
void DFS(int r, int c) {
  if (ch) {
    return;
  }

  visited[r][c] = true;
  for (int i = 0; i < 4; i++) {
    int rr = r + dy[i];
    int cc = c + dx[i];
    if (rr >= 0 && rr < m && cc >= 0 && cc < n) {
      if (l[rr][cc] == '.' && visited[rr][cc] == false) {
        if (checkOnBorder(rr, cc)) {
          ch = true;
          /* cout << int(ch); */
          visited[rr][cc] = true;
          p.push_back(make_pair(rr, cc));
          return;
        }
        if (cc >= 0 && cc < n && rr >= 0 && rr < m) {
          DFS(rr, cc);
        }
      }
    }
  }
}

void solve() {
  /* freopen("in.txt", "r", stdin); */
  /* freopen("out.txt", "w", stdout); */
  cin >> t;
  while (t--) {
    cin >> m >> n;
    init();
    for (int i = 0; i < m; i++) {
      cin >> l[i];
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (l[i][j] == '.' && checkOnBorder(i, j) && visited[i][j] == false) {
          /* visited[i][j] = true; */
          p.push_back(make_pair(i, j));
          DFS(i, j);
        }
      }
    }
    if (ch && p.size() == 2) {
      cout << "valid" << endl;
    } else {
      cout << "invalid" << endl;
    }
  }
}

int main() {
  // fastio;
  solve();

  return 0;
}
