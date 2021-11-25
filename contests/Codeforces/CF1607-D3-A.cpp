// time-limit: 1000
// problem-url: https://codeforces.com/contest/1607/problem/A

#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int char2int(string s, char a) {
  for (int i = 0; i < s.length(); ++i) {
    if (a == s[i])
      return i;
  }
  return -1;
}

int main() {
  fastio;
  int nt;
  cin >> nt;
  while (nt--) {
    int sum = 0;
    string k, w;
    cin >> k >> w;
    for (int i = 0; i < w.length() - 1; ++i) {
      sum += abs(char2int(k, w[i]) - char2int(k, w[i+1]));
    }
    cout << sum << endl;
  }
  return 0;
}
