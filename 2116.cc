#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  bool canBeValid(string s, string locked) {
    int left_max = 0, left_min = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (locked[i] == '1') {
        if (s[i] == '(') {
          ++left_max;
          ++left_min;
        } else if (s[i] == ')') {
          --left_max;
          left_min = max(left_min - 1, 0);
        }
      } else {
        ++left_max;
        left_min = max(left_min - 1, 0);
      }
      if (left_max < 0) {
        return false;
      }
    }
    return left_min == 0 && left_max % 2 == 0;
  }
};
