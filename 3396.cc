#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    unordered_set<int> seen_nums;
    int index = nums.size() - 1;
    while (index >= 0) {
      if (seen_nums.contains(nums[index])) {
        break;
      }
      seen_nums.insert(nums[index]);
      --index;
    }
    return (index + 3) / 3;
  }
};
