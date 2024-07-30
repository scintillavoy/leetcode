#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  int minimumDeletions(string s) {
    int dp_a = s[0] != 'a' ? 1 : 0;
    int dp_b = dp_a ^ 1;
    for (int i = 1; i < s.size(); ++i) {
      dp_b = min(dp_a, dp_b);
      if (s[i] == 'a') {
        ++dp_b;
      } else if (s[i] == 'b') {
        ++dp_a;
      }
    }
    return min(dp_a, dp_b);
  }
};
