// time-limit: 1000
// problem-url: https://codeforces.com/contest/71/problem/A

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
    while (n--) {
      string s;
      cin >> s;
      if (s.length() > 10) {
        cout << s[0] << s.length()-2 << s[s.length()-1] << endl;
      } else 
        cout << s << endl;
    }
    return 0;
}
