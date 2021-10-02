// time-limit: 2000
// problem-url: https://codeforces.com/contest/339/problem/A

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
    vector<int> v;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != '+')
        v.push_back(s[i]-'0');
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      cout << v[i];
      if (i != v.size() - 1)
        cout << "+";
    }
    return 0;
}
