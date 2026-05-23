#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> seen;
    int low = 0;
    int high = 0;
    while (high < nums.size() && high <= k) {
      if (seen.contains(nums[high])) {
        return true;
      }
      seen.insert(nums[high]);
      ++high;
    }
    while (high < nums.size()) {
      seen.erase(nums[low]);
      ++low;
      if (seen.contains(nums[high])) {
        return true;
      }
      seen.insert(nums[high]);
      ++high;
    }
    return false;
  }
};
