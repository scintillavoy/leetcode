#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nums1_count;
    for (const auto num : nums1) {
      ++nums1_count[num];
    }
    unordered_map<int, int> nums2_count;
    for (const auto num : nums2) {
      ++nums2_count[num];
    }
    vector<int> result(2);
    for (const auto [num, count] : nums1_count) {
      if (nums2_count.contains(num)) {
        result[0] += count;
      }
    }
    for (const auto [num, count] : nums2_count) {
      if (nums1_count.contains(num)) {
        result[1] += count;
      }
    }
    return result;
  }
};
