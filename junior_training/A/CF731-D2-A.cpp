#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    string s;
    cin >> s;
    int n_rot = 0;
    for (int i = 0; i < s.length(); i++) {
      int cw, ccw;
      if (i == 0) {
        cw = abs('a' - s[i]);
        ccw = 26 - cw;
      } else {
        cw = abs(s[i-1] - s[i]);
        ccw = 26 - cw;
      }
      if (cw > ccw)
        n_rot += ccw;
      else
        n_rot += cw;
    }
    cout << n_rot;
    return 0;
}
