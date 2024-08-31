#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }
    vector<string> result;
    int start_index = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] + 1 != nums[i]) {
        if (i - 1 == start_index) {
          result.push_back(to_string(nums[start_index]));
        } else {
          result.push_back(to_string(nums[start_index]) + "->" +
                           to_string(nums[i - 1]));
        }
        start_index = i;
      }
    }
    if (start_index == nums.size() - 1) {
      result.push_back(to_string(nums[start_index]));
    } else {
      result.push_back(to_string(nums[start_index]) + "->" +
                       to_string(nums.back()));
    }
    return result;
  }
};
