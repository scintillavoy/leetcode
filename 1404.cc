#include <string>
using namespace std;

class Solution {
 public:
  int numSteps(string s) {
    int count = 0;
    while (s.size() > 1) {
      ++count;
      if (s.back() == '0') {
        s.pop_back();
      } else {
        int index = s.size() - 1;
        while (index >= 0 && s[index] == '1') {
          s[index] = '0';
          --index;
        }
        if (index < 0) {
          s[0] = '1';
          s.push_back('0');
        } else {
          s[index] = '1';
        }
      }
    }
    return count;
  }
};
