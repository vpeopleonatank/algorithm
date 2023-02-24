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
    set<int> b;
    int count = 0;
    for (int i = 0; i < 3; i++) {
      if (!b.count(i)) {
        for (int j = i + 1; j < 4; j++) {
          if (a[j] == a[i]) {
            b.insert(j);
            count++;
          }  
        }
      }
    }
    cout << count;
    return 0;
}
