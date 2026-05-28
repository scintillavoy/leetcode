#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int findLUSlength(vector<string>& strs) {
    int max_length = -1;
    for (int i = 0; i < strs.size(); ++i) {
      bool common_exists = false;
      for (int j = 0; j < strs.size(); ++j) {
        if (i == j) {
          continue;
        }
        int m = 0;
        int n = 0;
        while (m < strs[i].size() && n < strs[j].size()) {
          if (strs[i][m] == strs[j][n]) {
            ++m;
          }
          ++n;
        }
        if (m == strs[i].size()) {
          common_exists = true;
          break;
        }
      }
      if (!common_exists) {
        max_length = max(max_length, (int)strs[i].size());
      }
    }
    return max_length;
  }
};
