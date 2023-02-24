#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

void solve() {
  while (1) {
    int n;
    cin >> n;
    if (n == 0)
      return;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    stack<int> b;
    int s = 1, t;
    for (int i = 0; i < n; i++) {
      if (s != a[i]) {
        b.push(a[i]);
      } else {
        s++;
      }
      while (!b.empty() && b.top() == s) {
        s++;
        b.pop();
      }
    }
    if (s > n)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
}

int main() {
  fastio;
  solve();

  return 0;
}
