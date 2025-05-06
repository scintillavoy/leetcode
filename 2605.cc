#include <algorithm>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minNumber(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> num_set(nums1.begin(), nums1.end());
    int common_num = 10;
    for (const auto num : nums2) {
      if (num_set.contains(num)) {
        common_num = min(common_num, num);
      }
    }
    if (common_num < 10) {
      return common_num;
    }
    int num1 = *min_element(nums1.begin(), nums1.end());
    int num2 = *min_element(nums2.begin(), nums2.end());
    if (num1 > num2) {
      swap(num1, num2);
    }
    return num1 * 10 + num2;
  }
};
