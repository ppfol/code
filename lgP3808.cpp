#include <array>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
auto with_index(T& t) {
  struct With_index {
    T& _t;
    struct Iterator {
      typename T::iterator t_i;
      size_t index{0};
      auto operator*() { return pair<decltype(*t_i)&, size_t>{*t_i, index}; }
      void operator++() { ++t_i; ++index; }
      bool operator!=(const Iterator& b) const { return t_i != b.t_i; }
    };
    Iterator begin() { return {_t.begin(), 0}; }
    Iterator end() { return {_t.end(), 0}; }
  };
  return With_index{t};
}

struct Acam {
  struct _Acam {
    array<_Acam*, 26> to;
    _Acam* fail{NULL};
    int cnt{0};
    _Acam() { to.fill(NULL); }
  };

  vector<_Acam> acam;
  _Acam* acam_head;
  Acam() {
    acam.push_back({});
    acam_head = &acam[0];
  }

  void insert(const string& s) {
    _Acam* now = acam_head;
    for (const char& c : s) {
      size_t ci = c - 'a';
      if (!now->to[ci]) {
        acam.push_back({});
        now->to[ci] = &acam.back();
      }
      now = now->to[ci];
    }
    now->cnt++;
  }

  void build_fail() {
    acam_head->fail = acam_head;
    queue<_Acam*> que;
    que.push(acam_head);
    while (!que.empty()) {
      _Acam* now = que.front();
      que.pop();
      for (auto [to, i] : with_index(now->to)) {
        if (to) {
          to->fail = now->fail->to[i];
          que.push(to);
        } else {
          to = now->fail->to[i];
        }
      }
    }
  }
};

int main() { return 0; }