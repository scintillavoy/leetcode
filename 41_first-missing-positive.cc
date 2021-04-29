#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
      while (0 < nums[i] && nums[i] <= nums.size() &&
             nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
    for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return nums.size() + 1;
  }
};

int main() {
  Solution sol;
  return 0;
}
