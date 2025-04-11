#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {
  ios::sync_with_stdio(false);

  int ans = 0;
  vector<string> p;
  string s = " ";

  for (string t; cin >> t, t != "."; p.push_back(t));
  for (string t; cin >> t && t != "……"; s += t);

  vector<int> dp(s.length());
  dp[0] = 1;
  for (int i = 1; i < s.length(); i ++) {
    for (const string& k : p) {
      int len = k.length();
      if (i >= len && dp[i - len] == 1 && k == s.substr(i - len + 1, len)) {
        dp[i] = 1;
        ans = i;
        break;
      }
    }
  }

  cout << ans;

  return 0;
}