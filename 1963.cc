#include <string>
using namespace std;

class Solution {
 public:
  int minSwaps(string s) {
    int opening_brackets = 0;
    for (const auto c : s) {
      if (c == '[') {
        ++opening_brackets;
      } else if (opening_brackets > 0) {
        --opening_brackets;
      }
    }
    return (opening_brackets + 1) / 2;
  }
};
