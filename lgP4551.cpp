#include <iostream>
#include <vector>
using namespace std;

struct Tree {
  int tot;
  vector<int> head, next, to, val, dis, vis;
  Tree(int n)
      : head(n + 1, -1),
        next(n * 2 - 2, -1),
        to(n * 2 - 2),
        val(n * 2 - 2),
        dis(n + 1),
        vis(n + 1, 0) {
    tot = 0;
  }
  void add(int u, int v, int w) {
    to[tot] = v;
    next[tot] = head[u];
    head[u] = tot;
    val[tot] = w;
    tot++;
  }
  void dis_cons(int now = 1, int p_xor = 0) {
    vis[now] = 1;
    dis[now] = p_xor;
    // cout << now << " " << p_xor << endl;
    for (int i = head[now]; i != -1; i = next[i]) {
      // cout << now << "#" << to[i] << "#" << vis[to[i]] << endl;
      if (vis[to[i]] == 0) {
        dis_cons(to[i], p_xor ^ val[i]);
      }
    }
  }
};
struct Trie {
  struct _Trie {
    int to[2]{0};
    int as = 0;
  };
  vector<_Trie> _trie;
  Trie() { _trie.push_back(_Trie()); }
  void add(int t) {
    int now = 0;
    for (int i = 31; i >= 0; i--) {
      int f = (t >> i) & 1;
      int& to = _trie[now].to[f];
      if (to != 0)
        now = to;
      else {
        now = to = _trie.size();
        _trie.push_back(_Trie());
      }
      // cout << f;
    }
    // cout << endl;
    _trie[now].as = t;
  }
  int search(int t) {
    int now = 0;
    for (int i = 31; i >= 0; i--) {
      int f = (t >> i) & 1;
      int* to = _trie[now].to;
      if (to[! f] != 0)
        now = to[! f];
      else {
        now = to[f];
      }
    }
    return _trie[now].as;
  }
};

int max_xor(int t = 0) {
  static int max = 0;
  if (t > max) max = t;
  return max;
}

int main() {
  ios::sync_with_stdio(false);
  int n, u, v, w;
  cin >> n;
  Tree tree(n);
  for (int i = 1; i < n; i++) {
    cin >> u >> v >> w;
    tree.add(u, v, w);
    tree.add(v, u, w);
  }
  tree.dis_cons();

  Trie trie;
  for (int i = 1; i <= n; i++) {
    trie.add(tree.dis[i]);
  }

  for (int i = 1; i <= n; i++) {
    max_xor(trie.search(tree.dis[i]) ^ tree.dis[i]);
  }

  cout << max_xor();
  return 0;
}