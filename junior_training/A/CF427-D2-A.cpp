#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int n;
    cin >> n;
    int n_police = 0, n_untreated = 0;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      if (t > 0) {
        n_police += t;
      } else {
        if (n_police) {
          n_police--;
        } else {
          n_untreated++;
        }
      }
    }
    cout << n_untreated;
    return 0;
}
