#include <iostream>
#include <cstring>
#include <vector>
using std::cin, std::cout, std::string;
using std::vector;

class Judge
{
public:
  int a;
  int b;
  Judge(): a(0), b(0) { }
  bool win(int t) {
    return ((a >= t || b >= t) && abs(a - b) >= 2);
  }
};

int main() {
  //std::ios::sync_with_stdio(0);

  vector<Judge> s11, s21;
  s11.emplace_back();
  s21.emplace_back();
  string t;
  while(true) {
    cin >> t;
    for (auto a : t) {
      if (a == 'E') goto A;
      if (a == 'W') {
        s11.back().a ++;
        s21.back().a ++;
      } else if (a == 'L') {
        s11.back().b ++;
        s21.back().b ++;
      }
      if (s11.back().win(11)) s11.emplace_back();
      if (s21.back().win(21)) s21.emplace_back();
    }
  }
  A:
  for (auto i : s11) {
    cout << i.a << ':' << i.b << '\n';
  }
  cout << '\n';
  for (auto i : s21) {
    cout << i.a << ':' << i.b << '\n';
  }
  system("pause");
  return 0;
}