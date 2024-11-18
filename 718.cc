#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    vector<int> max_lengths(nums2.size() + 1);
    int max_length = 0;
    for (int i = 0; i < nums1.size(); ++i) {
      vector<int> next_max_lengths(nums2.size() + 1);
      for (int j = 0; j < nums2.size(); ++j) {
        if (nums1[i] == nums2[j]) {
          next_max_lengths[j + 1] = max_lengths[j] + 1;
          max_length = max(max_length, next_max_lengths[j + 1]);
        }
      }
      max_lengths = next_max_lengths;
    }
    return max_length;
  }
};
