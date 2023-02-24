#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
  fastio;
    long long n;
    cin >> n;
    cout << n << " ";
    while (n != 1) {
      n = n % 2 == 0 ? n / 2 : n * 3 + 1;
      cout << n << " ";
    }
    return 0;
}
