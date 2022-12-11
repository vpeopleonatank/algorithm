#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

using namespace std;

int t, n, k;
long long x;
void solve() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    priority_queue<long long> p;
    for (int i = 0; i < n; i++) {
      cin >> x;
      p.push(x);
    }

    long long c = 0;
    while (k--) {
      x = p.top();
      c += x;
      p.pop();
      p.push(x / 2);
    }
    cout << c << endl;
  }
}

int main() {
  //fastio;
  solve();
  return 0;
}
