#include <bits/stdc++.h>

using namespace std;

void setIO(string s, int inputFromFile) {
  if (inputFromFile) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO("billboard", 1);
  int ll_x_b1, ll_y_b1, tr_x_b1, tr_y_b1, ll_x_b2, ll_y_b2, tr_x_b2, tr_y_b2,
      ll_x_t, ll_y_t, tr_x_t, tr_y_t;
  cin >> ll_x_b1 >> ll_y_b1 >> tr_x_b1 >> tr_y_b1 >> ll_x_b2 >> ll_y_b2 >>
      tr_x_b2 >> tr_y_b2 >> ll_x_t >> ll_y_t >> tr_x_t >> tr_y_t;
  int int_x_1 = min(tr_x_b1, tr_x_t) - max(ll_x_b1, ll_x_t);
  int int_y_1 = min(tr_y_b1, tr_y_t) - max(ll_y_b1, ll_y_t);
  int intersection1 = (int_x_1) * (int_y_1);
  int int_x_2 = min(tr_x_b2, tr_x_t) - max(ll_x_b2, ll_x_t);
  int int_y_2 = min(tr_y_b2, tr_y_t) - max(ll_y_b2, ll_y_t);
  int intersection2 = (int_x_2) * (int_y_2);
  int b_sum = (tr_x_b1 - ll_x_b1) * (tr_y_b1 - ll_y_b1) +
              (tr_x_b2 - ll_x_b2) * (tr_y_b2 - ll_y_b2);
  if (int_x_1 > 0)
    b_sum -= intersection1;
  if (int_x_2 > 0)
    b_sum -= intersection2;
  cout << b_sum;

  return 0;
}
