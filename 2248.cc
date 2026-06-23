#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<vector<int>>& nums) {
    vector<int> counts(1001);
    for (const auto& vec : nums) {
      for (const auto num : vec) {
        ++counts[num];
      }
    }
    vector<int> intersection;
    for (int i = 0; i < counts.size(); ++i) {
      if (counts[i] == nums.size()) {
        intersection.push_back(i);
      }
    }
    return intersection;
  }
};
