// time-limit: 1000
// problem-url: https://codeforces.com/contest/799/problem/A
#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  int n, t, k, d;
  cin >> n >> t >> k >> d;

  // Solution 1
  int bakedCakes = 0, twoOvenTime = 0;
  int oneOvenTime = ceil(n / (float)k) * t;
  while (bakedCakes < n) {
    twoOvenTime++;
    if (twoOvenTime % t == 0) {
      bakedCakes += k;
    }
    if (twoOvenTime > d && (twoOvenTime - d) % t == 0) {
      bakedCakes += k;
    }
  }

  if (twoOvenTime < oneOvenTime)
    cout << "YES";
  else
    cout << "NO";

  // Solution 2
  // float withoutTime = ceil(n / (float)k) * t;
  // float n_rem = n - (d / (float)t) * k;
  // float withTime = d + ceil(n_rem / (float)(2 * k)) * t;
  // if (withTime < withoutTime)
  //   cout << "YES";
  // else cout << "NO";

  // Solution 3:
  // int without = 0, with = 0, with_flag = 0, withoutFlag = 0, finishWith, finishWithout;
  // for (int curTime = 1;; curTime++) {
  //   if (curTime % t == 0) {
  //     without += k;
  //     with += k;
  //   }
  //   if ((curTime - d) % t == 0 && curTime > d) {
  //     with += k;
  //   }
  //   if (with_flag == 0 && with >= n) {
  //     finishWith = curTime;
  //     with_flag = 1;
  //   }
  //   if (withoutFlag == 0 && without >= n) {
  //     finishWithout = curTime;
  //     withoutFlag = 1;
  //   }
  //   if (with_flag && withoutFlag) {
  //     break;
  //   }
  // }
  // if (finishWith < finishWithout) {
  //   cout << "YES";
  // } else {
  //   cout << "NO";
  // }
  return 0;
}
