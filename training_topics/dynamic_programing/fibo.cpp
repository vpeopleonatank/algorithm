#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"
#define ll long long

using namespace std;
ll F[1005];

ll fibo(int n) {
  if (F[n] != -1) {
    return F[n];
  }
  if (n == 0) {
    return F[0] = 0;
  }

  if (n == 1) {
    return F[1] = 1;
  }
  F[n] = fibo(n - 1) + fibo(n - 2);
  return F[n];
}

void bottomUp(int n) {
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i <= n; ++i) {
    F[i] = F[i - 1] + F[i - 2];
  }
  cout << F[n];
}

int main() {
  fastio;
  int n;
  cin >> n;
  for (int i = 0; i <= n; ++i) {
    F[i] = -1;
  }
  cout << fibo(n);

  return 0;
}
