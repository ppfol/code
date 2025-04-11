#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
struct t{
  int i, j;
  t(int _i, int _j): i(_i), j(_j) { }
  bool operator<(const t& other) const {
    return tie(i, j) < tie(other.i, other.j);
  }
};
int main() {
  ios::sync_with_stdio(false);
  map<t, int> a;
  int n, q, t1, t2, t3, t4;
  cin >> n >> q;
  for (int i = 1; i <= q; i ++) {
    cin >> t1;
    if (1 == t1) {
      cin >> t2 >> t3 >> t4;
      a[t(t2, t3)] = t4;
    } else {
      cin >> t2 >> t3;
      cout << a[t(t2, t3)] << endl;
    }
  }
  return 0;
}