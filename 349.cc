#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<bool> occurrence1(1001);
    for (const auto num : nums1) {
      occurrence1[num] = true;
    }
    vector<bool> occurrence2(1001);
    for (const auto num : nums2) {
      occurrence2[num] = true;
    }
    vector<int> result;
    for (int i = 0; i < 1001; ++i) {
      if (occurrence1[i] && occurrence2[i]) {
        result.push_back(i);
      }
    }
    return result;
  }
};
