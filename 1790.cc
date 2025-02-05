#include <string>
using namespace std;

class Solution {
 public:
  bool areAlmostEqual(string s1, string s2) {
    bool should_swap = false;
    bool is_swapped = false;
    char from_ch;
    char to_ch;
    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] == s2[i]) {
        continue;
      }
      if (!should_swap) {
        should_swap = true;
        from_ch = s1[i];
        to_ch = s2[i];
      } else if (!is_swapped) {
        if (to_ch == s1[i] && from_ch == s2[i]) {
          is_swapped = true;
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
    return !should_swap || is_swapped;
  }
};
