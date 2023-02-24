#include <algorithm>
#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define ll long long

using namespace std;

int binarySearch(int k, int left, int right, vector<int> a) {
  if (right >= left) {
    int mid = (right + left) / 2;
    if (a[mid] == k) {
      return mid;
    }
    if (a[mid] > k)
      return binarySearch(k, left, mid - 1, a);

    return binarySearch(k, mid + 1, right, a);
  }
  return -1;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a;
  while(n != 0 && q != 0) {
    a.clear();
    int k;
    cin >> k;
    a.push_back(k);
    sort(a.begin(), a.end());
    int v = binarySearch(k, 0, a.size(), a);
    if (v != -1) {
      cout << k << " found at " << v;
    } else {
      cout << k << " not found";
    }
    cout << endl;
    cin >> n >> q;
  }
}

int main() {
  //fastio;
  solve();
  return 0;
}
