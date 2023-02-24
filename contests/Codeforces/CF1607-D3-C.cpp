// time-limit: 1000
// problem-url: https://codeforces.com/contest/1607/problem/C
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int tc;
    cin >> tc;
    while (tc--) {
      int n;
      cin >> n;
      vector<int> a(n);
      for (int i = 0; i < n; ++i) {
        cin >> a[i];
      }
      sort(a.begin(), a.end());
      int m = a[0];
      for (int i = 0; i < n - 1; ++i) {
        m = max(m, a[i + 1] - a[i]);
      }
      cout << m << endl;
    }
    return 0;
}
