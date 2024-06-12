#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int mid = 0;
    int right = n - 1;
    while (mid <= right) {
      if (nums[mid] == 0) {
        swap(nums[mid], nums[left]);
        ++left;
        ++mid;
      } else if (nums[mid] == 1) {
        ++mid;
      } else if (nums[mid] == 2) {
        swap(nums[mid], nums[right]);
        --right;
      }
    }
  }
};
