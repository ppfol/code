#include <iostream>
#include <cstdio>

using namespace std;
int a[2000001];
int main() {
  int n, m, t;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i ++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i ++) {
    scanf("%d", &t);
    printf("%d\n", a[t]);
  }

  return 0;
}