#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int primes[4] = {2, 3, 5, 7};
int n = 100;

int inc_exe(int idx = 0, int d = 1, int sign = -1) {
  if (idx == 4) {
    if (d == 1)
      return 0;
    return sign * n / d;
  }
  return inc_exe(idx+1, d, sign) + inc_exe(idx+1, d*primes[idx], sign * -1);
}

int inc_exe2() {
  int cnt = 0;
  for (int i2 = 0; i2 < 2; ++i2) {
    for (int i3 = 0; i3 < 2; ++i3) {
      for (int i5 = 0; i5 < 2; ++i5) {
        for (int i7 = 0; i7 < 2; ++i7) {
          cnt++;
        }
      }
    }
  }
  return cnt;
}

int main()
{
  fastio;
    cout << inc_exe();
    return 0;
}
