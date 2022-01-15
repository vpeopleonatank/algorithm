#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  // code goes here
  freopen("teleport.in", "r", stdin);
  freopen("teleport.out", "w", stdout);
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  if (a > b) {
    int t = a;
    a = b;
    b = t;
  }
  if (x > y) {
    int t = x;
    x = y;
    y = t;
  }
  cout << min({abs(a - b), abs(a - x) + abs(b - y)});

  return 0;
}
