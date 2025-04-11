#include <iostream>

using namespace std;

int n, m;
class Guy {
public:
  int direct;
  string career;
  Guy() {}
  Guy(int t1, string t2): direct(t1), career(t2) {}
};
Guy guys[100005];
int find(int now, int step) {
  int a = now + step;
  while (!(0 <= a && a < n)) {
    if (a < 0) a += n;
    if (a >= n) a -= n;
  }
  return a;
}

int main() {
  cin >> n >> m;
  int t1, t3;
  string t2;
  for (int i = 0; i < n; i ++) {
    cin >> t1 >> t2;
    guys[i] = Guy(t1 ? 1 : -1, t2);
  }
  int now = 0;
  for (int i = 0; i < m; i ++) {
    cin >> t1 >> t3;
    t1 = t1 ? 1 : -1;
    now = find(now, - t1 * t3 * guys[now].direct);
  }
  cout << guys[now].career;
  system("pause");
  return 0;
}
