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
  vector<long long> a(n + 1);
  vector<long long> s(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  s[0] = a[0];
  for (int i = 1; i < n; ++i) {
    s[i] = s[i - 1] + a[i];
  }
  vector<long long> m(3);
  m[0] = s[0];
  m[1] = s[1];
  m[2] = s[2];
  long long max_c = s[2];
  for (int i = 3; i < n; ++i) {
    max_c = max(max_c, s[i] - m[i % 3]);
    m[i % 3] = min(m[i % 3], s[i]);
  }
  cout << max_c;
  return 0;
}
