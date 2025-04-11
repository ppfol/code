#include <iostream>

class Oistr {
public:
  const size_t N = 10001;
  char raw_s[N];
  size_t len;

  Oistr(const char* _raw_s) {
    for (len = 0; _raw_s[len] != '\0'; len ++);
    strcpy(raw_s, _raw_s);
  }
  Oistr(const string &_raw_s) {
    len = _raw_s.length();
    strcpy(raw_s, _raw_s.c_str());
  }
  Oistr() {
    raw_s[0] = '\0';
    len = 0;
  }
  

};