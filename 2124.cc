#include <string>
using namespace std;

class Solution {
 public:
  bool checkString(string s) {
    int index = 0;
    while (index < s.size() && s[index] != 'b') {
      ++index;
    }
    if (index == s.size()) {
      return true;
    }
    while (index < s.size() && s[index] == 'b') {
      ++index;
    }
    return index == s.size();
  }
};
