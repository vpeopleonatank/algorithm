// time-limit: 1000
// problem-url: https://codeforces.com/problemset/problem/546/A
#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  int k, n, w;
  cin >> k >> n >> w;
  int c = 0;
  for (int i = 1; i <= w; i++) {
    c += i * k;
  }
  int r = c - n;
  if (r <= 0)
    cout << 0;
  else 
    cout << r;
  return 0;
}
