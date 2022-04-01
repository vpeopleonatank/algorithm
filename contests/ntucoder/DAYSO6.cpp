#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

#define ll long long
using namespace std;

ll f(int i, int j, int k) {
  return i + 2 * j + 3 * k;
}

int main() {
  fastio;
  int n;
  cin >> n;
  vector<long long> a(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll max_f = f(a[0], a[1], a[2]);
  ll vi = a[0], vj = a[1], vk = a[2];
  for (int i = 3; i < n; ++i) {
    if (a[i] > vk) {
      ll t_k = vk;
      vk = a[i];
      if (t_k > vj) {
        ll t_j = vj;
        vj = t_k;
        if (t_j > vi) {
          vi = t_j;
        }
      }
    max_f = f(vi, vj, vk); 
    }
  }
  cout << max_f; 
  return 0;
}
