#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  // code goes here
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (int i = 0; i < s.length(); i += 2) {
    if (s[i] == 'A')
      a += s[i + 1] - '0';
    else
      b += s[i + 1] - '0';
    if (a >= 10 && b >= 10) {
      if (a - b >= 2) {
        cout << "A";
        break;
      } else if (b - a >= 2) {
        cout << "B";
        break;
      }
    } else if (a >= 11) {
      cout << "A";
      break;
    } else if (b >= 11) {
      cout << "B";
      break;
    }
  }

  return 0;
}
