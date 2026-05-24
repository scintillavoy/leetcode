#include <string>
using namespace std;

class Solution {
 public:
  int partitionString(string s) {
    int seen = 0;
    int num_of_substrings = 1;
    for (int i = 0; i < s.size(); ++i) {
      int bit = 1 << s[i] - 'a';
      if ((seen & bit) != 0) {
        ++num_of_substrings;
        seen = 0;
      }
      seen |= bit;
    }
    return num_of_substrings;
  }
};
