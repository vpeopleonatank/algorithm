#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define endl "\n"

using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  while (n != 0) {
    deque<int> d;
    for (int i = 1; i <= n; ++i) {
      d.push_back(i);
    }
    cout << "Discarded cards: ";
    while (d.size() >= 2) {
      cout << d.front() << " ";
      d.pop_front();
      d.push_back(d.front());
      d.pop_front();
    }
    cout << endl << "Remaining card: " << d.front() << endl;
    cin >> n;
  }
  return 0;
}
