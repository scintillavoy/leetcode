#include <vector>
using namespace std;

class Solution {
 public:
  char repeatedCharacter(string s) {
    vector<bool> exist(26);
    for (const auto c : s) {
      if (exist[c - 'a']) {
        return c;
      }
      exist[c - 'a'] = true;
    }
    return -1;
  }
};
