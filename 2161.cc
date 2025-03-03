#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> result(nums.size());
    int left = 0;
    int right = result.size() - 1;
    for (const auto num : nums) {
      if (num == pivot) {
        continue;
      }
      if (num < pivot) {
        result[left] = num;
        ++left;
      } else {
        result[right] = num;
        --right;
      }
    }
    for (int i = left; i <= right; ++i) {
      result[i] = pivot;
    }
    reverse(result.begin() + right + 1, result.end());
    return result;
  }
};
