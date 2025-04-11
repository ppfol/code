#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

const int N = 100001;
const int M = 1000001;

int n, m;

struct Edge{
  int u, v;
  bool operator< (Edge t) {
    return u==t.u?v>t.v:u>t.u;
  }
};
Edge edges[M];

int head[N], nxt[M], to[M], cnt;
void add(int u, int v) {
  cnt ++;
  nxt[cnt] = head[u];
  head[u] = cnt;
  to[cnt] = v;
}

int vis[N];
void init() {
  for (int i = 1; i <= n; i ++)
    vis[i] = false;
}

struct Buffer_dfs {
  int key, save;
  Buffer_dfs(int t) {
    key = t;
    save = head[t];
  }
};
void dfs(int start) {
  stack<Buffer_dfs> stk;

  vis[start] = true;
  cout << start << " ";
  stk.push(Buffer_dfs(start));

  while (!stk.empty()) {
    Buffer_dfs now = stk.top();
    for (int& i = now.save; i != 0; i = nxt[i]) {
      int key = to[i];
      if (!vis[key]) {
        vis[key] = true;
        cout << key << " ";
        stk.push(Buffer_dfs(key));
        break;
      }
    }
    if (now.save == 0)
      stk.pop();
  }
}

struct Buffer_bfs {
  int key;
  Buffer_bfs(int t) {
    key = t;
  }
};
void bfs(int start) {
  queue<Buffer_bfs> que;

  vis[start] = true;
  cout << start << " ";
  que.push(Buffer_bfs(start));

  while(!que.empty()) {
    Buffer_bfs now = que.front();
    for (int i = head[now.key]; i != 0; i = nxt[i]) {
      int key = to[i];
      if (!vis[key]) {
        vis[key] = true;
        cout << key << " ";
        que.push(Buffer_bfs(key));
      }
    }
    que.pop();
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i ++) {
    cin >> edges[i].u >> edges[i].v;
  }
  sort(edges, edges+m);
  for (int i = 0; i < m; i ++) {
    add(edges[i].u, edges[i].v);
  }
  init();
  dfs(1);
  cout << endl;
  init();
  bfs(1);
  //system("pause");
  return 0;
}