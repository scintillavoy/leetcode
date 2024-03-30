#include <vector>
using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int end = nums.size();
    for (int i = 0; i < end; ++i) {
      while (nums[i] == val && i < end) {
        --end;
        swap(nums[i], nums[end]);
      }
    }
    return end;
  }
};
