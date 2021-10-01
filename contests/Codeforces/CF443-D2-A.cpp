// time-limit: 2000
// problem-url: https://codeforces.com/contest/443/problem/A

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
    getline(cin, s);
    set<char> letters;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '{' || s[i] == '}' || s[i] == ' ' || s[i] == ',')
        continue;
      letters.insert(s[i]);
    }

    cout << letters.size();
    return 0;
}
