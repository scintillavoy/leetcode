#include <string>
using namespace std;

class Solution {
 public:
  bool checkOnesSegment(string s) {
    int index = 0;
    while (index < s.size() && s[index] == '1') {
      ++index;
    }
    while (index < s.size() && s[index] == '0') {
      ++index;
    }
    return index == s.size();
  }
};
