#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int left = 0, right = 0;
    int odds = 0;
    while (odds < k && right < nums.size()) {
      if (nums[right] % 2 == 1) {
        ++odds;
      }
      ++right;
    }
    if (right == nums.size()) {
      return 0;
    }
    int result = 0;
    while (right <= nums.size()) {
      int count = 0;
      while (right < nums.size() && nums[right] % 2 == 0) {
        ++count;
        ++right;
      }
      result += count + 1;
      while (nums[left] % 2 == 0) {
        result += count + 1;
        ++left;
      }
      ++left;
      ++right;
    }
    return result;
  }
};
