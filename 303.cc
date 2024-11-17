#include <vector>
using namespace std;

class NumArray {
 public:
  NumArray(vector<int>& nums) {
    prefix_sums = vector<int>(nums.size() + 1);
    for (int i = 1; i < prefix_sums.size(); ++i) {
      prefix_sums[i] = prefix_sums[i - 1] + nums[i - 1];
    }
  }

  int sumRange(int left, int right) {
    return prefix_sums[right + 1] - prefix_sums[left];
  }

 private:
  vector<int> prefix_sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
