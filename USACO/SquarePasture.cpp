#include <bits/stdc++.h>

using namespace std;

void setIO(string s, int inputFromFile) {
  if (inputFromFile) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO("square", 1);
  int ll_x_a, ll_y_a, ur_x_a, ur_y_a, ll_x_b, ll_y_b, ur_x_b, ur_y_b;
  cin >> ll_x_a >> ll_y_a >> ur_x_a >> ur_y_a >> ll_x_b >> ll_y_b >> ur_x_b >>
      ur_y_b;
  int w = max(ur_x_a, ur_x_b) - min(ll_x_a, ll_x_b);
  int h = max(ur_y_a, ur_y_b) - min(ll_y_a, ll_y_b);
  cout << pow(max(w, h), 2);
  
  return 0;
}
