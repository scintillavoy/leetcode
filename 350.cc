#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> counts(1001);
    for (const auto num : nums1) {
      ++counts[num];
    }
    vector<int> result;
    for (const auto num : nums2) {
      if (counts[num] == 0) {
        continue;
      }
      --counts[num];
      result.push_back(num);
    }
    return result;
  }
};
