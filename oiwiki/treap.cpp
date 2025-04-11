#include <iostream>
#include <memory>
using namespace std;



class Treap {
public:
  class Node {
  public:
    static int _gc;
    int a, b, c, d;
    unique_ptr<Node> ch[2];
    Node(int _a): a(_a), b(rand()), c(1), d(1) { _gc ++; }
    ~Node() { _gc --; }
    /*
    // a 搜索对象
    // b 堆值
    // c 搜索对象 重复次数
    // d 子树和自身 所有节点 搜索对象 重复次数 之和
    // ch[0] 左子树 根节点 指针
    // ch[1] 右子树 根节点 指针
    */
    void upd_d() {
      d = c;
      if (ch[0]) d += ch[0]->d;
      if (ch[1]) d += ch[1]->d;
    }
    void prt(string space) {
      cout << space << a << "/" << b << "/" << c << "/" << d << endl;
      if (ch[0]) ch[0]->prt(space + " ");
      else if(ch[1]) cout << space << " left" << endl;
      if (ch[1]) ch[1]->prt(space + " ");
      else if(ch[0]) cout << space << " right" << endl;
    }
  };

  unique_ptr<Node> root;
  /*
  // 根节点 指针
  */
  enum Rot_dir { lr = 1, rr = 0 };
  void rot(unique_ptr<Node> &cur, const Rot_dir dir) {
    unique_ptr<Node> t = move(cur->ch[dir]);
    cur->ch[dir] = move(t->ch[!dir]);
    cur->upd_d();
    t->ch[!dir] = move(cur);
    t->upd_d();
    cur = move(t);
  }
  void insert(unique_ptr<Node> &cur, const int a) {
    if(!cur) {
      cur = make_unique<Node>(a);
    } else if (cur->a == a) {
      cur->c ++;
      cur->d ++;
    } else if (a < cur->a) {
      insert(cur->ch[0], a);
      cur->upd_d();

      if (cur->ch[0]->b < cur->b) {
        rot(cur, rr);
      }

    } else if (cur->a < a) {
      insert(cur->ch[1], a);
      cur->upd_d();

      if (cur->ch[1]->b < cur->b) {
        rot(cur, lr);
      }
    } else {}
  }
  void del(unique_ptr<Node> &cur, const int a) {
    if (!cur) {
    } else if (a < cur->a) {
      del(cur->ch[0], a);
      cur->upd_d();
    } else if (cur->a < a) {
      del(cur->ch[1], a);
      cur->upd_d();
    } else if (cur->a == a && cur->c > 1) {
      cur->c --;
      cur->d --;
    } else if (cur->a == a && cur->c == 1) {
      unsigned int opt = 0b00;
      if (cur->ch[0]) opt |= 0b10;
      if (cur->ch[1]) opt |= 0b01;
      switch (opt) {
      case 0b00:
        cur = nullptr;
        break;
      case 0b10:
        cur = move(cur->ch[0]);
        break;
      case 0b01:
        cur = move(cur->ch[1]);
        break;
      case 0b11:
        Rot_dir dir = cur->ch[0]->b < cur->ch[1]->b ? rr : lr;
        rot(cur, dir);
        del(cur->ch[!dir], a);
        cur->upd_d();
        break;
      }
    } else {}
  }
  pair<int, int> q_by_a(const unique_ptr<Node> &cur, const int a) const {
    //pair< (<), (<=) >
    if (!cur) {
      return {0, 0};
    } else {
      int less = cur->ch[0] ? cur->ch[0]->d : 0;
      if (cur->a == a) {
        return {less, less + cur->c};
      } else if (a < cur->a) {
        return q_by_a(cur->ch[0], a);
      } else {
        pair<int, int> t = q_by_a(cur->ch[1], a);
        return {less + cur->c + t.first, less + cur->c + t.second};
      }
    }
  }
  int q_by_rank(const unique_ptr<Node> &cur, const int rank) const {
    // rank = (<=)
    if (!cur || cur->d <= rank || rank < 0) {
      return -1;
    } else {
      int less = cur->ch[0] ? cur->ch[0]->d : 0;
      if (rank < less) {
        return q_by_rank(cur->ch[0], rank);
      } else if (rank < less + cur->c) {
        return cur->a;
      } else {
        return q_by_rank(cur->ch[1], rank - cur->c - less);
      }
    }
  }
  void insert(int a) { insert(root, a); }
  void del(int a) { del(root, a); }
  pair<int, int> q_by_a(const int a) const { return q_by_a(root, a); }
  int q_by_rank(const int rank) const {return q_by_rank(root, rank); }
  void prt() {
    if (root) root->prt("");
  }
};
int Treap::Node::_gc = 0;


int main() {
  srand(time(0));
  if (1) {
    Treap a;
    int is[] {1, 7, 8, 9, 10, 10, 10, 6, 6};
    for (auto i : is) {
      a.insert(i);
    }
    a.prt();
    a.del(6);
    a.del(10);
    a.prt();
    cout << a.q_by_a(1).first << " " << a.q_by_a(1).second << endl;
    cout << a.q_by_a(10).first << " " << a.q_by_a(10).second << endl;
    cout << a.q_by_a(7).first << " " << a.q_by_a(7).second << endl;
    cout << a.q_by_a(-1000).first << " " << a.q_by_a(-1000).second << endl;
    cout << a.q_by_a(1000).first << " " << a.q_by_a(1000).second << endl;
    cout << a.q_by_rank(-1) << endl;
    cout << a.q_by_rank(0) << endl;
    cout << a.q_by_rank(10000) << endl;
    cout << a.q_by_rank(1) << endl;
    cout << a.q_by_rank(2) << endl;
    cout << a.q_by_rank(3) << endl;
    cout << a.q_by_rank(4) << endl;
    cout << a.q_by_rank(5) << endl;
    cout << a.q_by_rank(6) << endl;
    cout << a.q_by_rank(7) << endl;
    cout << a.q_by_rank(8) << endl;
    cout << a.q_by_rank(9) << endl;

    cout << Treap::Node::_gc;
  }

  system("pause");
  return 0;
}