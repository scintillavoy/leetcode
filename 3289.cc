#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getSneakyNumbers(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      while (nums[i] != i && nums[i] != nums[nums[i]]) {
        swap(nums[i], nums[nums[i]]);
      }
    }
    return {nums[nums.size() - 2], nums[nums.size() - 1]};
  }
};
