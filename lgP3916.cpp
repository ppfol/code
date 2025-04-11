#include <iostream>
#include <queue>

using namespace std;

const int N = 100001;
const int M = 100001;

int n, m;

int head[N], nxt[M], to[M], cnt;
void add(int u, int v) {
  cnt ++;
  nxt[cnt] = head[u];
  head[u] = cnt;
  to[cnt] = v;
}

int vis[N], num;

void bfs(int start) {
  queue<int> que;
  vis[start] = start;
  num ++;
  que.push(start);
  while(!que.empty()) {
    int now = que.front();
    for (int i = head[now]; i != 0; i = nxt[i]) {
      int key = to[i];
      if (!vis[key]) {
        vis[key] = start;
        num ++;
        que.push(key);
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
    add(b, a);
  }
  for (int i = n; i >= 1 && num < n; i --)
    if (!vis[i])
      bfs(i);
  for (int i = 1; i <= n; i ++)
    cout << vis[i] << " ";
  system("pause");
  return 0;
}