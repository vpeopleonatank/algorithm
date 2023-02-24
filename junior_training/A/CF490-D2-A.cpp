// time-limit: 1000
// problem-url: https://codeforces.com/contest/490/problem/A

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

    // Solution 2
    vector<vector<int>> teams(3, vector<int>());
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      teams[k-1].push_back(i+1);
    }

    int min_len =
        min(min(teams[0].size(), teams[1].size()), teams[2].size());
    cout << min_len << endl;
    if (min_len > 0) {
      for (int i = 0; i < min_len; i++) {
        cout << teams[0][i] << " " << teams[1][i] << " " << teams[2][i] << endl;
      }
    }

    // Solution 1
    // vector<int> vec(n);
    // for (int i = 0; i < n; i++) {
    //   cin >> vec[i];
    // }
    // vector<vector<int>> teams;
    // vector<bool> checked(n, 0);
    // for (int i = 0; i < n; i++) {
    //   if (checked[i]) {
    //     continue;
    //   }
    //   set<int> s;
    //   vector<int> team;
    //   s.insert(vec[i]);
    //   team.push_back(i+1);
    //   for (int j = i + 1; j < n; j++) {
    //     if (s.count(vec[j]) == 0 && checked[j] == 0) {
    //       checked[j] = true;
    //       s.insert(vec[j]);
    //       team.push_back(j+1);
    //     }
    //     if (s.size() == 3) {
    //       teams.push_back(team);
    //       break;
    //     }
    //   }
    // }
    // cout << teams.size() << endl;
    // if (teams.size() != 0) {
    //   for (int i = 0; i < teams.size(); i++) {
    //     for(int j = 0; j < 3; j++)
    //       cout << teams[i][j] << " ";
    //     cout << endl;
    //   }
    // }

    return 0;
}
