#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200010;

int n; struct Tsk{ int w, t; }tsk[N]; bool wP(Tsk a, Tsk b) { return a.w >
b.w; } bool tP(Tsk a, Tsk b) { return a.t > b.t; }

int nxt[N];

int main() {
  cin >> n;
  for (int i = 1; i<= n; i ++) {
    cin >> tsk[i].t >> tsk[i].w;
  }
  //sort(tsk+1, tsk+n+1, tP);
  /*do not need to sort t.
  because if there's avaliable between t1 and t2,
  the tsk with bigger can be include no matter the another how.
  else the two tsk is equal.*/
  sort(tsk+1, tsk+n+1, wP);
  
  for (int i = 0; i <= N; i ++) {
    nxt[i] = i;
  }
  
  int val = 0;
  for (int i = 1; i <= n; i ++) {
    if (nxt[tsk[i].t]) {
      nxt[tsk[i].t] = nxt[nxt[tsk[i].t]-1];
      /*we should keep "nxt" always updated and avaliable.
      so the nst moved should link to another nxt(updated).*/
      val += tsk[i].w;
    }
  }
  cout << val;
  return 0;
}
