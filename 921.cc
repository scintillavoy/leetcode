#include <string>
using namespace std;

class Solution {
 public:
  int minAddToMakeValid(string s) {
    int unpaired_opening = 0;
    int unpaired_closing = 0;
    for (const auto c : s) {
      if (c == '(') {
        ++unpaired_opening;
      } else {
        if (unpaired_opening > 0) {
          --unpaired_opening;
        } else {
          ++unpaired_closing;
        }
      }
    }
    return unpaired_opening + unpaired_closing;
  }
};
