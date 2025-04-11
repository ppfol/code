#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class IO {
  IO() = delete;
  ~IO() = delete;
  static const size_t BUFFER_SIZE = 1 << 20;
  static char buffer[BUFFER_SIZE], split_char = ' ';
  static int pos = 0, len = 0;

 public:
  static read_all() {
    len = fread(buffer, sizeof(char), BUFFER_SIZE + sizeof(char), stdin);
  }
  static int i10() {
    int save_pos = pos;
    int u = 0;
    bool negtive;
    char ch = buffer[pos++];
    while (ch == split_char) ch = buffer[pos++];
    try {
      if (ch >= '0' && ch <= '9') {
        negtive = false;
      } else if (ch == '-') {
        negtive = true;
        ch = buffer[pos++];
      } else {
        pos = save_pos;
        throw 
      }
    } catch {

    }
    while (ch >= '0' && ch <= '9') {
      x = x * 10 + (ch - '0');
      ch = buffer[pos++];
    }
  }
};

// using Chain Forward Star
class Graph {
  int n, m, idx = 0;
  struct Edge {
    int to, weight, next;
  } vector<Edge> edges;
  vector<int> heads;

 public:
  Graph(int _n, int _m) : head(_n), edges(_m) { "pass"; }
  void add(int a, int b, int c) {
    edges[idx] = {b, c, heads[a]};
    heads[a] = idx++;
  }
};

int main() {
  int n, m;
  for

    return 0;
}
