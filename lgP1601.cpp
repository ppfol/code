#include <iostream>
using namespace std;

class Num {
public:
  char a[10000];
  int len;
  Num(string s) {
    len = s.length();
    for (int i = len - 1, j = 0; i >= 0; i --, j ++) {
      a[j] = s[i] - '0';
    }
  }
  string output() {
    string s = "";
    for (int i = len - 1; i >= 0; i --) {
      s = s + (char)(a[i]+'0');
    }
    return s;
  }
  friend Num operator+(const Num&, const Num&);
};

Num operator+(const Num& a, const Num& b) {
  Num ans("0");
  int up = 0, i;
  for (i = 0; i < a.len || i < b.len || up > 0; i ++) {
    ans.a[i] = (a.a[i] + b.a[i] + up) % 10;
    up = (a.a[i] + b.a[i] + up) / 10;
  }
  ans.len = i;
  return ans;
}


int main() {
  string sa, sb;
  cin >> sa >> sb;
  cout << (Num(sa) + Num(sb)).output();
  system("pause");
  return 0;
}