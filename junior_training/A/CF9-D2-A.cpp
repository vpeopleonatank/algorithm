#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int gcd(int x, int y) {
  if (y == 0) 
    return x;
  else
    return gcd(y, x % y);
}

int main()
{
    fastio;
    int y, w;
    cin >> y >> w;
    int numerator = 6 - max(y, w) + 1;
    int denominator = 6;
    int m = gcd(numerator, denominator);
    cout << numerator / m << "/" << denominator / m;
    return 0;
}
