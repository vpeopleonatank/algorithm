#include <bits/stdc++.h>
#include <vector>

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
    vector<vector<int>> teams;
    for (int i = 0; i < n; i++) {
      vector<int> a;
      a.push_back(0);
      a.push_back(0);
      cin >> a[0] >> a[1];
      teams.push_back(a);
    }
    int count = 0;
    for (int i = 0; i < teams.size(); i++) {
      for (int j = 0; j < teams.size(); j++) {
        if (i != j && teams[i][0] == teams[j][1]) {
          count++;
        }
      }
    }
    cout << count;
    return 0;
}
