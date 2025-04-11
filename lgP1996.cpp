#include <iostream>

using namespace std;
int a[101];
int n, m;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i ++) {
    a[i] = i + 1;
  }
  a[n] = 1;
  int now = 1, cnt = 0, yo = 1, k;
  while (cnt < n) {
    if (yo == m) {
      yo = 1;
      cout << now << ' ';
      now = a[k] = a[now];
      cnt ++;
    } else {
      k = now;
      now = a[now];
      yo ++;
    }
  }
  return 0;
}