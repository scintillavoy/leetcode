#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums) {
    vector<int> indices{0};
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[indices.back()] < nums[i]) {
        indices.push_back(i);
      }
    }
    int answer = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
      while (!indices.empty() && nums[indices.back()] > nums[i]) {
        answer = max(answer, i - indices.back() + 1);
        indices.pop_back();
      }
    }
    return answer;
  }
};
