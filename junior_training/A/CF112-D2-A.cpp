#include <bits/stdc++.h>

using namespace std;

int solve() {
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < a.length(); ++i) {
    if(tolower(a[i]) < tolower(b[i]))
      return -1;
    else if (tolower(a[i]) > tolower(b[i])) 
      return 1;
  }
  return 0;
}

int main() {
  cout << solve();
}

