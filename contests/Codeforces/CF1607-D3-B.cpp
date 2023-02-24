// time-limit: 1000
// problem-url: https://codeforces.com/contest/1607/problem/B
#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

long long get(long long n) {
  int k = n % 4;
  if (k == 1)
    return -n;
  else if (k == 2)
    return 1;
  else if (k == 3)
    return n + 1;
  else
    return 0;
}

int main() {
  fastio;
  int nt;
  cin >> nt;
  while (nt--) {
    long long x, n;
    cin >> x >> n;
    if (x % 2 == 0)
      cout << x + get(n);
    else
      cout << x - get(n);
    cout << endl;
  }
  return 0;
}
