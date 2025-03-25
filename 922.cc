#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& nums) {
    int odd_index = 1;
    for (int even_index = 0; even_index < nums.size(); even_index += 2) {
      while (nums[even_index] % 2 == 1) {
        swap(nums[even_index], nums[odd_index]);
        odd_index += 2;
      }
    }
    return nums;
  }
};
