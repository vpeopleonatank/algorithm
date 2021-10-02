#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cin >> m;
    while (m--) {
      int x, y;
      cin >> x >> y;
      if (x-1-1 >= 0)
        a[x-1-1] += y - 1;
      if (x+1-1 < n)
        a[x + 1 - 1] += a[x - 1] - y;
      a[x-1] = 0;
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << endl;
    }
    return 0;
}
