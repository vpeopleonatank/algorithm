// time-limit: 1000
// problem-url: https://codeforces.com/contest/709/problem/A

#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int n, b, d;
    cin >> n >> b >> d;
    int cur = 0, count = 0;
    while (n--) {
      int a;
      cin >> a;
      if (a > b) {
        continue;
      }
      cur += a;
      if (cur > d) {
        cur = 0;
        count++;
      }
    }
    cout << count;
    return 0;
}
