#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  int a[n], first = 0, second = 0, start = 0, end = n - 1;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    int num;
    if (a[start] > a[end]) {
      num = a[start];
      start++;
    } else {
      num = a[end];
      end--;
    }
    if (i % 2 == 0) {
      first += num;
    } else {
      second += num;
    }
  }
  cout << first << " " << second;
  return 0;
}
