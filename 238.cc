#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    vector<int> answer(len);
    answer[len - 1] = nums[len - 1];
    for (int i = len - 2; i >= 0; --i) {
      answer[i] = answer[i + 1] * nums[i];
    }
    for (int i = 1; i < len; ++i) {
      nums[i] *= nums[i - 1];
    }
    answer[0] = answer[1];
    for (int i = 1; i < len - 1; ++i) {
      answer[i] = nums[i - 1] * answer[i + 1];
    }
    answer[len - 1] = nums[len - 2];
    return answer;
  }
};
