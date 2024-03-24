#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    int positive = -1, negative = -1;
    vector<int> answer;
    for (int i = 0; i < nums.size(); i += 2) {
      do {
        ++positive;
      } while (nums[positive] < 0);
      do {
        ++negative;
      } while (nums[negative] > 0);
      answer.push_back(nums[positive]);
      answer.push_back(nums[negative]);
    }
    return answer;
  }
};
