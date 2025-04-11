#include <iostream>
using namespace std;

class Num {
public:
  char dig[10000]{};
  int len;
  Num(string s) {
    int sufz = 0;
    for (int i = s.length() - 1, j = 0; i >= 0; i --, j ++) {
      dig[j] = s[i] - '0';
      sufz = dig[j] ? 0 : sufz+1;
    }
    len = s.length() - sufz;
    if (len == 0) len = 1;
  }
  string s() {
    string s = "";
    for (int i = len - 1; i >= 0; i --) {
      s = s + (char)(dig[i]+'0');
    }
    return s;
  }
  friend Num operator+(const Num&, const Num&);
  friend Num operator*(const Num&, const Num&);
//private:
  friend Num operator*(const Num&, const int&);
};

Num operator+(const Num& a, const Num& b) {
  Num ans("");
  int up = 0, i;
  for (i = 0; i < a.len || i < b.len || up > 0; i ++) {
    ans.dig[i] = (a.dig[i] + b.dig[i] + up) % 10;
    up = (a.dig[i] + b.dig[i] + up) / 10;
  }
  ans.len = i;
  return ans;
}
Num operator*(const Num& a, const Num& b) {
  Num ans("0");
  string fix;
  for (int i = 0; i < a.len; i ++, fix += "0") {
    ans = ans + Num((b * (int)a.dig[i]).s() + fix);
  }
  return ans;
}
Num operator*(const Num& a, const int& b) {
  Num ans("");
  int up = 0, i;
  for (i = 0; i < a.len || up > 0; i ++) {
    ans.dig[i] = (a.dig[i] * b + up) % 10;
    up = (a.dig[i] * b + up) / 10;
  }
  ans.len = i;
  return ans;
}

int main() {
  int n;
  cin >> n;
  Num ans("1"), multi("1");
  char t[5];
  for (int i = 2; i <= n; i ++) {
    sprintf(t, "%d", i);
    multi = Num(string(t)) * multi;
    ans = ans + multi;
  }
  cout << ans.s();
  system("pause");
  return 0;
}