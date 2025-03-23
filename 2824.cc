#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int countPairs(vector<int>& nums, int target) {
    int num_of_pairs = 0;
    sort(nums.begin(), nums.end());
    int start = 0;
    int end = nums.size() - 1;
    while (start < end) {
      if (nums[start] + nums[end] < target) {
        num_of_pairs += end - start;
        ++start;
      } else {
        --end;
      }
    }
    return num_of_pairs;
  }
};
