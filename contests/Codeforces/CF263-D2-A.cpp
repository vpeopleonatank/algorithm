#include <bits/stdc++.h>

using namespace std;

int main() {
  for (int i = 0; i < 25; i++) {
    int val;
    cin >> val;
    if (val == 1) {
      int row = i / 5;
      int col = i % 5;
      cout << abs(row - 2) + abs(col - 2);
    }
  }
}
