#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if ((a <= c && c <= b) || (a <= d && d <= b) || (c <= a && a <= d) ||
      (c <= b && b <= d)) {
    cout << max(b, d) - min(a, c);
  } else
    cout << (b - a) + (d - c);

  return 0;
}
