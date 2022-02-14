#include <bits/stdc++.h>

using namespace std;

void setIO(string s, int status) {
  if (status) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO("word", 1);
  int n, k;
  cin >> n >> k;
  string s;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    cur += s.length();
    if (cur <= k) {
      if (i != 0) cout << " ";
      cout << s;
    } else {
      cout << endl << s;
      cur = s.length();
    }
  }
  return 0;
}
