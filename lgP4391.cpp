#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  string a;
  int len;
  cin >> len >> a;
  vector<int> pi(len);
  for (int i = 1; i < len; i ++) {
    int j = pi[i - 1];
    while (j > 0 && a[j] != a[i]) j = pi[j - 1];
    if (a[j] == a[i]) j ++;
    pi[i] = j;
  }
  cout << len - pi[len - 1];
  return 0;
}