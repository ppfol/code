#include <iostream>
#include <memory>
using namespace std;

class Rbtree {
public:
  enum Color { Red, Black };
  class Node {
  public:
    static int _gc;
    shared_ptr<Node> ch[2], p;
    Color color;
    int k, v;
    Node(int _k, int _v): color(Red), k(_k), v(_v) { _gc ++; }
    ~Node() { _gc --; }
  };

  shared_ptr<Node> root;
  int count = 0;

  enum Rot_dir { lr = 1, rr = 0 };
  void rot(shared_ptr<Node> &cur, Rot_dir dir) {
    shared_ptr<Node> t = cur->ch[dir];
    t->p = cur->p;
    cur->ch[dir] = t->ch[!dir];
    t->ch[!dir]->p = cur;
    cur->p = t;
    t->ch[!dir] = cur;
    cur = t;
  }
  void insert() {
    
  }
};

int Rbtree::Node::_gc = 0;

int main() {


  return 0;
}