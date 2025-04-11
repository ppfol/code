#include <iostream> 

using namespace std;

char a[105][105];
int n, m;

int count(int ii, int jj) {
  int c = 0;
  for (int i = -1; i <= 1; i ++)
    for (int j = -1; j <= 1; j ++)
      if(a[ii + i][jj + j] == '*')
        c ++;
  return c;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i ++)
    scanf("%s", a[i]+1);
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      if (a[i][j] == '*') cout << '*';
      else cout << count(i, j);
    }
    cout << '\n';
  }
  system("pause");
}