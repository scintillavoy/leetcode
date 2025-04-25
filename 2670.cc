#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> distinctDifferenceArray(vector<int>& nums) {
    vector<int> result(nums.size());
    unordered_set<int> seen_nums;
    for (int i = 0; i < nums.size(); ++i) {
      seen_nums.insert(nums[i]);
      result[i] = seen_nums.size();
    }
    seen_nums.clear();
    for (int i = nums.size() - 1; i >= 0; --i) {
      result[i] -= seen_nums.size();
      seen_nums.insert(nums[i]);
    }
    return result;
  }
};
