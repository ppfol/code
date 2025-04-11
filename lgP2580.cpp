#include <iostream>
#include <vector>

using namespace std;

struct Trie {
  struct _Trie {
    int to[26]{0};
    bool is_name;
    bool called = false;
    _Trie(bool _is_name) : is_name(_is_name) {}
  };
  vector<_Trie> _trie;
  Trie() { _trie.push_back(_Trie(false)); }
  void add(const string& t) {
    int now = 0;
    for (int i = 0; i < t.length(); i++) {
      int& z = _trie[now].to[t[i] - 'a'];
      if (z != 0) {
        now = z;
      } else {
        now = z = _trie.size();
        _trie.push_back(_Trie(false));
      }
    }
    _trie[now].is_name = true;
  }
  int call(const string& t) {
    int now = 0;
    for (int i = 0; i < t.length(); i++) {
      int& z = _trie[now].to[t[i] - 'a'];
      if (z != 0) {
        now = z;
      } else {
        return 2;
      }
    }
    if (_trie[now].is_name) {
      if (! _trie[now].called) {
        _trie[now].called = true;
        return 0;
      } else return 1;
    } else return 2;
  }
} trie;

int main() {
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n;
  string t;
  while (n --) {
    cin >> t;
    trie.add(t);
  }
  cin >> m;
  while (m --) {
    cin >> t;
    switch (trie.call(t)) {
      case 0:
        cout << "OK" << endl;
        break;
      case 1:
        cout << "REPEAT" << endl;
        break;
      case 2:
        cout << "WRONG" << endl;
        break;
    } 
  }
  return 0;
}