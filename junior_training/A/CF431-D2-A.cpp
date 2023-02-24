#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int a[4];
    for(int i = 0; i < 4; i++)
      cin >> a[i];
    string s;
    cin >> s;
    int n_calo = 0;
    for (int i = 0; i < s.length(); i++) {
      for (int j = 0; j < 4; j++) {
        if (s[i] - '0' == j + 1) {
          n_calo += a[j];
          break;
        }
      }
    }
    cout << n_calo;
    return 0;
}
