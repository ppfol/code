#include <iostream>

using namespace std;

const int N = 1e6+10;

int main() {
  unsigned short n, b, a[N];
  cin >> n >> b;
  int cas, have;
  for (int i = 1; i <= N-1; i ++) {
    a[i] = 0;
  }
  int t, min = N, max = 0;
  for (int i = 1; i <= n; i ++) {
    cin >> t;
    a[t] ++;
    if (t < min) {
      min = t;
    }
    if (t > max) {
      max = t;
    }
  }
  if (min >= b) {
    cas = b;
    b = 0;
    have = min;
  } else {
    cas = min;
    b -= min;
    have = min;
  }
  int add = a[min];
  for (int i = min+1; i <= N; i ++) {
    if (b >= 1 && cas+1 >= add) {
      have ++;
      b --;
      cas -= add-1;
    } else if (b == 0 && cas >= add) {
      have ++;
      cas -= add;
    } else break;
    add += a[i];
  }
  cout << have;
  return 0;
}
