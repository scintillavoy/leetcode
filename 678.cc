#include <string>
using namespace std;

class Solution {
 public:
  bool checkValidString(string s) {
    int left = 0, right = 0, empty = 0;
    int diff = 0;
    for (const auto &c : s) {
      switch (c) {
        case '(':
          ++diff;
          break;
        case ')':
          --diff;
          if (diff < 0) {
            if (right > 0) {
              ++diff;
              --right;
              ++empty;
            } else if (empty > 0) {
              ++diff;
              --empty;
              ++left;
            } else {
              return false;
            }
          }
          break;
        case '*':
          if (diff > 0) {
            --diff;
            ++right;
          } else if (diff < 0) {
            ++diff;
            ++left;
          } else {
            ++empty;
          }
          break;
      }
    }
    return diff == 0;
  }
};
