#include <iostream>
#include <vector>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  string a, b, c;
  cin >> a >> b;
  c = b + "#" + a;
  vector<int> pi(c.length());
  for (int i = 1; i < c.length(); i ++) {
    int j = pi[i - 1];
    while (j > 0 && c[j] != c[i]) j = pi[j - 1];
    if (c[i] == c[j]) j ++;
    pi[i] = j;
  }
  for (int i = b.length() + 1, j = 0; i < c.length(); i ++, j ++) {
    if (pi[i] == b.length())
      cout << j - b.length() + 2 << endl;
  }
  for (int i = 0; i < b.length(); i ++) {
    cout << pi[i] << " ";
  }
}