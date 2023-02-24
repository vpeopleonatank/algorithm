#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int n;
    cin >> n;
    string pre;
    int n_groups = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      if (i == 0) {
        n_groups++;
        pre = s;
        continue;
      }
      if (pre != s) {
        n_groups++;
      }
      pre = s;
    }
    cout << n_groups;
    return 0;
}
