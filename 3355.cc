#include <vector>
using namespace std;

class Solution {
 public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> possible_decrements(nums.size() + 1);
    for (const auto& query : queries) {
      ++possible_decrements[query[0]];
      --possible_decrements[query[1] + 1];
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (possible_decrements[i] < nums[i]) {
        return false;
      }
      possible_decrements[i + 1] += possible_decrements[i];
    }
    return true;
  }
};
