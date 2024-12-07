#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> orArray(vector<int>& nums) {
    vector<int> result(nums.size() - 1);
    for (int i = 0; i < result.size(); ++i) {
      result[i] = nums[i] | nums[i + 1];
    }
    return result;
  }
};
