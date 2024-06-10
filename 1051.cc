#include <vector>
using namespace std;

class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    vector<int> counts(101);
    for (const auto height : heights) {
      ++counts[height];
    }
    int result = 0;
    for (int i = 0, j = 1; i < heights.size(); ++i) {
      while (j < counts.size() && counts[j] == 0) {
        ++j;
      }
      if (j != heights[i]) {
        ++result;
      }
      --counts[j];
    }
    return result;
  }
};
