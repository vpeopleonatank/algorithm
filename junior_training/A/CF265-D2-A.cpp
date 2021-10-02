#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    string s, t;
    cin >> s >> t;
    int cur_pos = 0;
    for (int i = 0; i < t.length(); i++) {
      if (t[i] == s[cur_pos]) {
        cur_pos++;
      }
    }
    cout << cur_pos + 1;
    return 0;
}
