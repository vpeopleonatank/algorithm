#include <bits/stdc++.h>
#include <tuple>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

using namespace std;

int n, m, k, cnt;
vector<string> org(51);
vector<string> dup(51);

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void DFS(vector<string> &s, pair<int, int> p) {
  int r = p.first;
  int c = p.second;
  s[r][c] = '*';
  for (int i = 0; i < 4; i++) {
    int nr = r + dy[i];
    int nc = c + dx[i];
    if (nr >= 0 && nr < n && nc >= 0 && nc < m && s[nr][nc] == '.') {
      cnt++;
      DFS(s, make_pair(nr, nc));
    }
  }
}

void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> org[i];
    dup[i] = org[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        /* if (i == 0 || i == n - 1 || j == 0 || j == m - 1) */
        /*   c2++; */
      if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && dup[i][j] == '.') {
        DFS(dup, make_pair(i, j));
      }
    }
  }
  /* for (int i = 0; i < n; i = i + n - 1) { */
  /*   for (int j = 0; j < m; j++) { */
  /*     if (dup[i][j] == '.') { */
  /*       DFS(dup, make_pair(i, j)); */
  /*     } */
  /*   } */
  /* } */
  /* for (int j = 0; j < m; j = j + m - 1) { */
  /*   for (int i = 1; i < n - 1; i++) { */
  /*     if (dup[i][j] == '.') { */
  /*       DFS(dup, make_pair(i, j)); */
  /*     } */
  /*   } */
  /* } */
  vector<tuple<int, int, int>> lakes;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (dup[i][j] == '.') {
        cnt = 1;
        DFS(dup, make_pair(i, j));
        lakes.push_back(make_tuple(cnt, i, j));
      }
    }
  }
  sort(lakes.begin(), lakes.end());
  int cnt = 0, i = 0;
  while (i < lakes.size() - k) {
    cnt += get<0>(lakes[i]);
    DFS(org, make_pair(get<1>(lakes[i]), get<2>(lakes[i])));
    i++;
  }
  /* cout << endl << lakes.size() << endl; */
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << org[i] << endl;
  }
}

int main() {
  // fastio;
  /* freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout); */
  solve();
  return 0;
}
