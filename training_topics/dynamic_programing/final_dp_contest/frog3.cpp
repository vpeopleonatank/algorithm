#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> f(n + 1, 0);

  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] += f[i - 1];
    if (i > 2)
      f[i] += f[i - 2];

  }
  cout << f[n];
  return 0;
}
