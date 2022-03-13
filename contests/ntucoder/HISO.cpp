#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    a.push_back(k);
  }

  vector<int> m(n + 1);
  vector<int> h(n + 1);
  int f = a[1] - a[0];
  m[1] = f > 0 ? f : 0;
  h[1] = a[0] > a[1] ? 1 : 0;

  for (int i = 2; i < n; ++i) {
    if (a[h[i - 1]] < a[i]) {
      h[i] = h[i-1];
    } else {
      h[i] = i;
    }
    m[i] = max(a[i] - a[h[i]], m[i - 1]);
  }
  cout << m[n-1];

  return 0;
}
