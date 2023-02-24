#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

bool isPerfectSquare(long long n) {
  if (pow((int)sqrt(n), 2) == n)
    return true;
  return false;
}

int main() {
  fastio;
  long long n;
  vector<long long> v;
  cin >> n;
  while (n != 0) {
    v.push_back(n);
    cin >> n;
  }
  for (int i = 0; i < v.size(); i++) {
    if (!isPerfectSquare(v[i]))
      printf("no");
    else
      printf("yes");
    printf("\n");
  }
  return 0;
}
