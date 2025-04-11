#include <iostream>
#include <vector>
using namespace std;

struct Trie {
  struct _Trie {
    int to[26]{0};
    bool end;
    _Trie(bool _end) : end(_end) {}
  };
  vector<_Trie> a;
  Trie() { a.push_back(_Trie(false)); }
  int add(const string& t) {
    int now = 0, cah = 0;
    for (int i = 0; i < t.length(); i++) {
      cah += (a[now].end ? 1 : 0);
      if (a[now].to[t[i] - 'a'] != 0) {
        now = a[now].to[t[i] - 'a'];
        //cout << t[i] << endl;
      } else {
        now = a[now].to[t[i] - 'a'] = a.size();
        a.push_back(_Trie(i == t.length() - 1));
        //cout << now << " " << t[i] << endl; 
      }
    }
    return cah + 1;
  }
} trie;

int max_cah(int t = 0) {
  static int cah = 0;
  if (t > cah) cah = t;
  return cah;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  string s;
  cin >> n;
  while (n--) {
    cin >> s;
    max_cah(trie.add(s));
    //cout << "---------" << endl;
  }
  cout << max_cah();
  return 0;
}