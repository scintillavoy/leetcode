#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumIndex(vector<int>& nums) {
    unordered_map<int, int> counts;
    for (int i = 0; i < nums.size(); ++i) {
      ++counts[nums[i]];
    }
    int dominant_num = 0;
    for (const auto [num, count] : counts) {
      if (count > nums.size() / 2) {
        dominant_num = num;
      }
    }
    int dominant_count_left = 0;
    int dominant_count_right = counts[dominant_num];
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] == dominant_num) {
        ++dominant_count_left;
        --dominant_count_right;
      }
      if (dominant_count_left > (i + 1) / 2 &&
          dominant_count_right > (nums.size() - 1 - i) / 2) {
        return i;
      }
    }
    return -1;
  }
};
