#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, h;
  cin >> n >> h;
  int sum = 0, current;
  for (int i = 0; i < n; i++) {
    cin >> current;
    if (current <= h) {
      sum += 1;
    } else {
      sum += 2;
    }
  }
  cout << sum;
}
