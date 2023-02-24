#include <bits/stdc++.h>

using namespace std;

void setIO(string s, int useFileInput) {
  if (useFileInput) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

struct point {
  int x;
  int y;
};

int main() {
  setIO("buckets", 1);
  char c;
  point B, R, L;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> c;
      switch (c) {
        case 'B':
          B.x = i;
          B.y = j;
          break;
        case 'R':
          R.x = i;
          R.y = j;
          break;
        case 'L':
          L.x = i;
          L.y = j;
          break;
      }
    }
  }
  int step = 0;
  if (abs(L.x - R.x) + abs(R.x - B.x) == abs(L.x - B.x) &&
      abs(L.y - R.y) + abs(R.y - B.y) == 0)
    cout << abs(L.x - B.x) + 1;
  else if (abs(L.y - R.y) + abs(R.y - B.y) == abs(L.y - B.y) &&
      abs(L.x - R.x) + abs(R.x - B.x) == 0)
    cout << abs(L.y - B.y) + 1;
  else 
    cout << abs(L.x - B.x) + abs(L.y - B.y) - 1;

  
  return 0;
}
