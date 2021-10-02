// time-limit: 1000
// problem-url: https://codeforces.com/contest/770/problem/A

#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
  fastio;
    int n, k;
    cin >> n >> k;
    vector<int> chars;
    string s = "";
    int cur_char = (int)'a';
    int cur_index = 0;
    for (int i = 0; i < n; ++i) {
      if (chars.size() < k) {
        s += (char) cur_char;
        chars.push_back(cur_char);
        cur_char++;
      } else {
        s += chars[cur_index];
        cur_index++;
        if (cur_index == k)
          cur_index = 0;
      }
    }
    cout << s;
    return 0;
}
