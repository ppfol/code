#include <iostream>
#include <queue>

using namespace std;

const int N = 5001;
const int M = 500001;
const int MOD = 80112002;

int n, m, ans;

int gtab[N][N];
int num[N], cnt[N];
void bfs() {
  queue<int> que;
  for (int i = 1; i <= n; i ++) {
    if (!gtab[0][i]) {
      num[i] = 1;
      que.push(i);
    }
  }
  while (!que.empty()) {
    int now = que.front();
    for (int i = 1; i <= n; i ++) {
      if (!gtab[now][i]) continue;
      cnt[i] ++;
      num[i] = (num[i] + num[now])%MOD;
      if (cnt[i] == gtab[0][i]) {
        que.push(i);
      }
    }
    que.pop();
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i ++) {
    int a, b;
    cin >> a >> b;
    gtab[a][b] = 1;
    gtab[a][0] ++;
    gtab[0][b] ++;
  }
  bfs();
  for (int i = 1; i <= n; i ++) {
    if (!gtab[i][0]) {
      ans = (ans + num[i])%MOD;
    }
  }
  cout << ans;
  //system("pause");
  return 0;
}