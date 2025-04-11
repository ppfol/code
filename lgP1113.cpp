#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 10001;

int n, len[N], cnt[N], cost[N], fromn[N];
vector<int> to[N];

void bfs(int start) {
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int now = que.front();
    for (int i = 0; i < (int)to[now].size(); i ++) {
      int key = to[now][i];
      cnt[key] ++;
      cost[key] = max(cost[key], cost[now]);
      if(cnt[key] == fromn[key]) {
        cost[key] += len[key];
        que.push(key);
      }
    }
    que.pop();
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i ++) {
    int a, b;
    cin >> a;
    cin >> len[a];
    do {
      cin >> b;
      to[b].push_back(a);
      fromn[a] ++;
    } while (b != 0);
  }
  bfs(0);
  int maxx = 0;
  for (int i = 1; i <= n; i ++) {
    maxx = max(maxx, cost[i]);
  }
  cout << maxx;
  //system("pause");
  return 0;
}