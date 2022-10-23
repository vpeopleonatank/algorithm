#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int len = 0, cnt = 0, l = 0, ml, mr;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      cnt++;
      if (cnt > k) {
        while (cnt > k) {
          if (a[l] == 0) {
            cnt--;
          }
          l++;
        }
      }
    }
    if (len < i - l + 1) {
      len = i - l + 1;
      ml = l;
      mr = i;
    }
  }
  cout << len << endl;
  for (int i = 0; i < n; ++i) {
    if (i >= ml && i <= mr)
      cout << 1;
    else
      cout << a[i];
    cout << " ";

  }

  return 0;
}
