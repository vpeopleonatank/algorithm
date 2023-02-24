#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

using namespace std;

void solve() {
  int q, t, v;
  cin >> q;
  priority_queue<int, vector<int>, greater<int>> pq;
  priority_queue<int, vector<int>, greater<int>> tmp;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> v;
      pq.push(v);
    } else if (t == 2) {
      cin >> v;
      tmp.push(v);
    } else {
      while (!pq.empty() && !tmp.empty() && pq.top() == tmp.top()) {
        pq.pop();
        tmp.pop();
      }
      cout << pq.top();
    }
  }
}

int main() {
  //fastio;
  solve();
  return 0;
}


