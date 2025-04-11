#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gtab[27][27], n;
vector<string> lib[27][27];

int main () {

  cin >> n;
  for (int i = 1; i <= n; i ++) {
    string t;
    cin >> t;
    int a = t[0]-'a';
    int b = t[t.size()-1]-'a';
    lib[a][b].push_back(t);
    gtab[a][b] ++;
  }
  for (int i = 0; i < 26; i ++)
    for (int j = 0; j < 26; j ++)
      sort(lib[i][j].begin(), lib[i][j].end());
  return 0;
}