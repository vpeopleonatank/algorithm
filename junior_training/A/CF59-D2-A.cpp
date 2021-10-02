#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  string s;
  cin >> s;
  int low_n = 0, up_n = 0;
  for (int i = 0; i < s.length(); i++) {
    if (tolower(s[i]) == s[i]) {
      low_n++;
    } else {
      up_n++;
    }
  }
  if (up_n <= low_n)
    for (int i = 0; i < s.length(); i++)
      cout << char(tolower(s[i]));
  else
    for (int i = 0; i < s.length(); i++)
      cout << char(toupper(s[i]));
  return 0;
}
