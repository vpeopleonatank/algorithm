#include <bits/stdc++.h>
#include <utility>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

using namespace std;

int main() {
  fastio;
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> a(n);
  vector<int> b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  int c = 0, j = 0;
  vector<pair<int, int>> p;
  for (int i = 0; i < n && j < m; i++) {
    if (a[i] - x <= b[j] && a[i] + y >= b[j]) {
      c++;
      p.push_back(pair<int, int>(i + 1, j + 1));
      j++;
    } else if (a[i] + y < b[j]) {
      continue;
    } else if (a[i] - x > b[j]) {
      i--;
      j++;
    }
  }
  cout << p.size() << endl;
  for (int i = 0; i < p.size(); i++) {
    cout << p[i].first << " " << p[i].second << endl;
  }
  
  return 0;
}
