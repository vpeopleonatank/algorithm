#include <bits/stdc++.h>

using namespace std;

void setIO(string s, int status) {
  if (status) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO("promote", 1);
  int bBronze, aBronze, bSilver, aSilver, bGold, aGold, bPlatium, aPlatium;
  cin >> bBronze >> aBronze >> bSilver >> aSilver >> bGold >> aGold >>
      bPlatium >> aPlatium;
  int goldToPlatium = aPlatium - bPlatium;
  int silverToGold = aGold - bGold + goldToPlatium;
  int bronzeToSilver = aSilver - bSilver + silverToGold;
  cout << bronzeToSilver << endl << silverToGold << endl << goldToPlatium;


  return 0;
}
