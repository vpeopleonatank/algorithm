// https://atcoder.jp/contests/dp/tasks/dp_k
#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  // trang thai thang/thua (1/0) cua nguoi hien tai khi co i vien soi
  vector<int> f(k + 1, 0);
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < a.size(); j++) {
      if (a[j] <= i) {
        if (f[i - a[j]] == 0) {
          f[i] = 1;
          continue;
        }
      }
    }
  }
  if (f[k] == 1)
    cout << "First";
  else
    cout << "Second";
  return 0;
}
