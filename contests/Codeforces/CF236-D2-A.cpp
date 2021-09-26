#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    set<char> chars;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      chars.insert(s[i]);
    }
    if(chars.size() % 2 == 0)
      cout << "CHAT WITH HER!";
    else
      cout << "IGNORE HIM!";
    return 0;
}
