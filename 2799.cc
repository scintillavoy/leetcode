#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int countCompleteSubarrays(vector<int>& nums) {
    unordered_set<int> nums_set;
    for (const auto num : nums) {
      nums_set.insert(num);
    }
    int result = 0;
    int start = 0;
    unordered_map<int, int> nums_map;
    for (int end = 0; end < nums.size(); ++end) {
      ++nums_map[nums[end]];
      int preceding_count = 0;
      while (nums_map.size() == nums_set.size()) {
        --nums_map[nums[start]];
        if (nums_map[nums[start]] == 0) {
          nums_map.erase(nums[start]);
        }
        ++start;
        ++preceding_count;
      }
      result += preceding_count * (nums.size() - end);
    }
    return result;
  }
};
