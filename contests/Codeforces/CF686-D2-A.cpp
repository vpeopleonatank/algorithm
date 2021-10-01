// time-limit: 2000
// problem-url: https://codeforces.com/contest/686/problem/A

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
    long long x;
    cin >> n >> x;
    int n_kids = 0;
    while (n--) {
      char c;
      long long d;
      cin >> c >> d;
      if (c == '+')
        x += d;
      else {
        if (x < d) {
          n_kids++;
        } else {
          x -= d;
        }
      }
    }
    cout << x << " " << n_kids;
    return 0;
}
