#include <bits/stdc++.h>

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define endl "\n"
#define ll long long

using namespace std;

struct point {
  int x, y;
};

double getd(point a, point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
  fastio;
  int n, target, d;
  cin >> n >> target >> d;
  vector<point> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].x;
    cin >> p[i].y;
  }
  int f1 = 0, f2 = 0;
  vector<point> i1, i2;
  target -= 1;
  for (int i = 0; i < n; ++i) {
    if (i == target)
      continue;
    if (getd(p[target], p[i]) < d) {
      f1++;
      i1.push_back(p[i]);
    } else {
      f2++;
      i2.push_back(p[i]);
    }
  }
  int f2_num = 0;
  for (int i = 0; i < f2; ++i) {
    for (int j = 0; j < f1; j++) {
      if (getd(i1[j], i2[i]) < d) {
        f2_num++;
        break;
      }
    }
  }
  cout << f1 << " " << f2_num;

  return 0;
}
