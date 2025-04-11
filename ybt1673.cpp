#include <bits/stdc++.h>

const long long N = 1e6+10;

using namespace std;

inline long long read() {
  long long res = 0; char c;
  while ((c = getchar()) < '0' || c > '9');
  res = c-'0';
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res*10)+(c-'0');
  return res;
}

struct Pnt{
  long long h, v;
}t;

struct Heap{
  Pnt pnt[N];
  long long len = 0;
  long long hh = 0;
  long long tot = 0;
  void push(Pnt res) {
    len ++;
    hh += res.h;
    tot += 1ll*res.h*res.v;
    long long now = len, nxt = now/2;
    while (nxt >= 1) {
      if (res.v < pnt[nxt].v) {
        pnt[now] = pnt[nxt];
        now = nxt;
        nxt = now/2;
      } else break;
    } pnt[now] = res;
  }
  void pop() {
    Pnt res = pnt[len];
    len --; /*be careful overflow*/
    hh -= pnt[1].h;
    tot -= 1ll*pnt[1].h*pnt[1].v;
    long long now = 1, nxt = 2;
    while (nxt <= len) {
      if (nxt+1 <= len && pnt[nxt+1].v < pnt[nxt].v) {
        nxt ++;
      }
      if (pnt[nxt].v < res.v) {
        pnt[now] = pnt[nxt];
        now = nxt;
        nxt = now*2;
      } else break;
    } pnt[now] = res;
  }
}heap;

int main() {
  long long n, m;
  n = read();
  m = read(); m ++;
  long long bs = 0, maxx = 0;
  for (long long i = 1; i <= n; i ++) {
      t.h = read(); t.h --;
      t.v = read();
      bs += t.v;
      if (m-i == 0) {
        maxx = max(maxx, bs);
        break;
      } else if (t.h > 0) {
        heap.push(t);
        while (heap.len > 0 && heap.hh - heap.pnt[1].h >= m-i) heap.pop();
        if (heap.hh < m-i) maxx = max(maxx, heap.tot+bs);
        else maxx = max(maxx, heap.tot-1ll*heap.pnt[1].v*(heap.hh-m+i)+bs);
      }
  }
  cout << maxx;
  return 0;
}


