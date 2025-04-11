#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  stack<int> st;
  char c;
  int t;
  while (true) {
    c = cin.peek();
    if ('0' <= c && c <= '9') {
      cin >> t;
      //cout << "(" << t << ")";
      st.push(t);
    } else {
      c = cin.get();
      if (c == '@') break;
      else if (c == '.') continue;
      else {
        int b = st.top(); st.pop();
        int a = st.top(); st.pop();
        if (c == '+') st.push(a + b);
        else if (c == '-') st.push(a - b);
        else if (c == '*') st.push(a * b);
        else if (c == '/') st.push(a / b);
      }
    }
  }
  cout << st.top();

  return 0;
}