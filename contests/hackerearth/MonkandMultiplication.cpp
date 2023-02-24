#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

using namespace std;
priority_queue<int> p;

void solve() {
  int n;
  cin >> n;
  int a[n+1];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long first, second, third;
  for (int i = 0; i < n; i++) {
    if (i == 0 || i == 1) {
      cout << -1 << endl;
      p.push(a[i]);
      continue;
    }
    p.push(a[i]);
    first = p.top();
    p.pop();
    second = p.top();
    p.pop();
    third = p.top();
    p.pop();
    cout << first * second * third << endl;
    p.push(third);
    p.push(second);
    p.push(first);
  } 
}

int main() {
  //fastio;
  solve();
  return 0;
}
