#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canPermutePalindrome(string s) {
    vector<bool> is_odd(26);
    for (const auto &ch : s) {
      is_odd[ch - 'a'] = !is_odd[ch - 'a'];
    }
    bool has_odd = false;
    for (const auto &x : is_odd) {
      if (x) {
        if (has_odd) {
          return false;
        }
        has_odd = true;
      }
    }
    return true;
  }
};
