#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  vector<int> a(7);
  for (int i = 0; i < 7; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  printf("%d %d %d", a[0], a[1], a[6] - a[0] - a[1]);
  return 0;
}
