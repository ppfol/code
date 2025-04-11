/*
BY ppfol
DT 20230629
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

const int N = 100001;
const int W = 11;
const int BW = 0x3f3f3f3f;

int read() {
  int t = 0;
  bool f = false;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = true;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    t = t * 10 + (c - '0');
    c = getchar();
  }
  return f ? -t : t;
}  // for int
void write(int t) {
  if (t < 0) {
    putchar('-');
    t = -t;
  }
  if (t > 9) write(t / 10);
  putchar(t % 10 + '0');
}  // for int

typedef int T;
// T API <, <=, fea(alternative)
typedef int F;
// template <typename T>
// template <typename F>
int nn, ww = 10;
T idata[N], odata[N];
void input() {
  nn = read();
  for (int i = 1; i <= nn; i++) {
    odata[i] = idata[i] = read();
  }
}  // T==int requested
void output() {
  for (int i = 1; i <= nn; i++) {
    write(idata[i]);
    putchar(' ');
  }
}  // T==int requested
void reset() { memcpy(idata + 1, odata + 1, nn); }

int time1, time2;
int timer(bool say = false) {
  time1 = time2;
  time2 = clock();
  if (say) cout << (time2 - time1) << "ms" << endl;
  return time2 - time1;
}

void swap(T &a, T &b) {
  int t = a;
  a = b;
  b = t;
}

void stlSort(T num[], int a, int b) {
  // introsort
  sort(num + a, num + b + 1);
}

void selectionSort(T num[], int a, int b) {
  /*
  Stability: false
  Time Complexity.
    Bast: O(n^2)
    Average: O(n^2)
    Worst: O(n^2)
  Memory Complexity: O(n)
  Stay in place: true;
  Data Featrue: null;
  */
  for (int i = b; i >= a; i--) {
    int v = 0, k = 0;
    for (int j = a; j <= i; j++) {
      if (v < num[j]) {
        v = num[j];
        k = j;
      }
    }
    swap(num[k], num[i]);
  }
}

void bubbleSort(T num[], int a, int b) {
  /*
  Stability: true
  Time Complexity.
    Bast: O(n) as order.
    Average: O(n^2)
    Worst: O(n^2) as disorder.
  Memory Complexity: O(n)
  Stay in place: true;
  */
  for (int i = b; i >= a; i--) {
    bool flag = false;
    for (int j = a; j < i; j++) {
      if (num[j + 1] < num[j]) {
        flag = true;
        swap(num[j], num[j + 1]);
      }
    }
    if (!flag) break;
  }
}

int bFind(T num[], int a, int b, T t) {
  if (a == b) return (num[a] <= t) ? a : a - 1;
  int m = (a + b) / 2;
  if (num[m] <= t)
    return bFind(num, m + 1, b, t);
  else
    return bFind(num, a, m, t);
}
void insertionSort(T num[], int a, int b) {
  /*
  Stability: true
  Time Complexity.
    Bast: O(n) as order.
    Average: O(n^2)
    Worst: O(n^2) as disorder.
  Memory Complexity: O(n)
  Stay in place: true;
  */
  for (int i = a; i < b; i++) {
    int t = num[a];
    int c = bFind(num, b - (i - a), b, t);
    memmove(num + a, num + a + 1, sizeof(T) * (c - a));  // O(n)
    num[c] = t;
  }
}

F fea(T t, int n) {
  if (n == -1) {
    if (t < 0)
      return -1;
    else
      return 1;
  } else {
    for (int i = 1; i <= n; i++) t /= 10;
    return t % 10;
  }
}  // T==int requested
void countingSort(T num[], int a, int b, int order, F getKey(T, int)) {
  /*
  Stability: true
  Time Complexity.
    Bast: O(n)
    Average: O(n)
    Worst: O(n)
  Memory Complexity: O(n+w)
  Stay in place: false;
  Data Featrue: few kinds of keys;
  */
  map<F, queue<T>> cw;
  for (int i = a; i <= b; i++) {
    cw[getKey(num[i], order)].push(num[i]);
  }
  int j = a;
  for (auto i = cw.begin(); i != cw.end(); i++) {
    while (!i->second.empty()) {
      num[j] = i->second.front();
      i->second.pop();
      j++;
    }
  }
}
void radixSort(T num[], int a, int b, F getKey(T, int)) {
  for (int i = 0; 1; i++) {
    bool flag = false;
    F t = getKey(num[a], i);
    for (int j = a + 1; j <= b; j++) {
      if (t != getKey(num[j], i)) {
        flag = true;
        break;
      }
    }
    if (flag)
      countingSort(num, a, b, i, getKey);
    else
      break;
  }
  countingSort(num, a, b, -1, fea);
}  // based on countingSort (alternative)

void quicksort(T num[], int a, int b) {
  if (a == b) return;
  int p = a, q = b;
  int m = (a + b) / 2;
  while (p < q) {
    while (num[p] < num[m] && p < q) p++;
    while (num[m] <= num[p] && p < q) q--;
    if (p < q) swap(num[p], num[q]);
  }
  int d = b;
  while (p < d) {
    while (num[p] == num[m] && p < d) p++;
    while (num[d] != num[m] && p < d) d--;
    if (p < d) swap(num[p], num[d]);
  }
  quicksort(num, a, q);
  quicksort(num, p, b);
}

T tnum[N];
void mergeSort(T num[], int a, int b) {
  if (a == b) return;
  int m = (a + b) / 2;
  mergeSort(num, a, m);
  mergeSort(num, m + 1, b);
  int p = a, q = m + 1, t = a;
  while (t <= b) {
    if (p > m) {
      while (t <= b) {
        tnum[t] = num[q];
        t++;
        q++;
      }
      break;
    } else if (q > b) {
      while (t <= b) {
        tnum[t] = num[p];
        t++;
        p++;
      }
      break;
    } else if (num[p] <= num[q]) {
      tnum[t] = num[p];
      p++;
      t++;
    } else {
      tnum[t] = num[q];
      q++;
      t++;
    }
  }
  memcpy(num + a, tnum + a, sizeof(T) * (b - a + 1));
}
struct Heap {
  T t[N];
  int tail = 0;
  void add(T a) {
    tail++;
    t[tail] = a;
    int k = tail;
    while (k / 2) {
      if (t[k / 2] < t[k]) {
        swap(t[k], t[k / 2]);
        k = k / 2;
      } else
        break;
    }
  }
  T pop() {
    int k = 1;
    while (k * 2 + 1 <= tail) {
      if (t[k * 2] < t[k * 2 + 1]) {
        swap(t[k], t[k * 2 + 1]);
        k = k * 2 + 1;
      } else {
        swap(t[k], t[k * 2]);
        k = k * 2;
      }
    }
    if (k * 2 == tail) swap(t[k], t[k * 2]);
    tail--;
    return t[tail + 1];
  }
};
void heapSort(T num[], int a, int b) {
  Heap h;
  for (int i = a; i <= b; i++) h.add(num[i]);
  for (int i = b; i >= a; i--) num[i] = h.pop();
}

int main() {
  input();

  timer();
  heapSort(idata, 1, nn);
  timer(1);

  output();
  system("pause");
  return 0;
}
