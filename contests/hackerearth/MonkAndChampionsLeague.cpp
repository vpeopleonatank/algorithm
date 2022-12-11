#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

using namespace std;

void solve() {
  int n, m;
  cin >> m >> n;
  int a[m + 1];
  priority_queue<int> p;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    p.push(a[i]);
  }
  int c = 0;
  while (n--) {
    int k = p.top();
    c += k;
    p.pop();
    p.push(--k);
  }
  cout << c;
}

int main() {
  // fastio;
  solve();
  return 0;
}
