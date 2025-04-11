#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Trie {
  struct _Trie {
    int to[2] {0};
    int cnt = 0;
  };
  vector<_Trie> _trie;
  Trie() { _trie.push_back(_Trie()); }
  void add(long long t) {
    int now = 0;
    for (int i = 33; i >= 0; i --) {
      int f = (t >> i) & 1;
      int& to = _trie[now].to[f];
      if (to) {
        now = to;
      } else {
        now = to = _trie.size();
        _trie.push_back(_Trie());
      }
      _trie[now].cnt ++;
    }
  }
  long long qur(long long t, int k) {
    int now = 0;
    long long key = 0;
    for (int i = 33; i >= 0; i --) {
      int f = (t >> i) & 1;
      int* to = _trie[now].to;
      if (_trie[to[!f]].cnt >= k) {
        now = to[!f];
        key = (key << 1) | (!f);
      } else {
        k -= _trie[to[!f]].cnt;
        now = to[f];
        key = (key << 1) | f;
      }
    }
    //cout << key << "," << t << endl;
    return key ^ t;
  }
};

struct Q_item {
  long long val;
  int t, k;
  bool operator<(const Q_item& t) const {
    return val < t.val;
  }
};

int main() {
  ios::sync_with_stdio(false);
  int n, k;
  long long ans = 0;
  cin >> n >> k;
  k *= 2;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n ; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i ++) {
    a[i] ^= a[i - 1];
  }
  Trie trie;
  for (int i = 0; i <= n; i ++) {
    trie.add(a[i]);
  }
  priority_queue<Q_item> que;
  for (int i = 0; i <= n; i ++) {
    que.push({trie.qur(a[i], 1), i, 1});
  }
  while (k --) {
    Q_item t = que.top();
    que.pop();
    ans += t.val;
    //cout << "#" << t.val << endl;
    que.push({trie.qur(a[t.t], t.k + 1), t.t, t.k + 1});
  }
  cout << ans / 2;
  return 0;
}