#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> memo;
    for (int i = 0; i < nums.size(); ++i) {
      if (memo.count(nums[i]) == 1) {
        return {memo[nums[i]], i};
      }
      memo[target - nums[i]] = i;
    }
    return {-1, -1};
  }
};

int main() { return 0; }
