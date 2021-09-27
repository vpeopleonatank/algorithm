#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int k, r;
    cin >> k >> r;
    for (int i = 1;; i++) {
      if (i * k % 10 == 0 || i * k % 10 == r) {
        cout << i;
        break;
      }
    }
    return 0;
}
