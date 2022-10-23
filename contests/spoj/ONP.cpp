#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    stack<char> c;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(')
        continue;
      else if (s[i] == ')') {
        cout << c.top();
        c.pop();
      } else if (s[i] >= 'a' && s[i] <= 'z')
        cout << s[i];
      else
        c.push(s[i]);
    }
    cout << endl;
  }
  return 0;
}
