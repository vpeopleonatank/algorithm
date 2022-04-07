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
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    int dp[a.length() + 1][b.length() + 1];
    for (int j = 1; j <= a.length(); j++)
      dp[j][0] = j;
    for (int j = 1; j <= b.length(); j++)
      dp[0][j] = j;
    dp[0][0] = 0;
    for (int j = 1; j <= a.length(); j++) {
      for (int k = 1; k <= b.length(); k++) {
        if (a[j - 1] == b[k - 1])
          dp[j][k] = dp[j - 1][k - 1];
        else
          dp[j][k] = min(dp[j - 1][k],
                         min(dp[j][k - 1], dp[j - 1][k - 1])) + 1;
      }
    }
    cout << dp[a.length()][b.length()] << endl;
  }

  return 0;
}
