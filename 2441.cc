#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMaxK(vector<int>& nums) {
    int answer = -1;
    vector<bool> exist(2001);
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        exist[nums[i]] = true;
        if (exist[nums[i] + 1000]) {
          answer = max(answer, nums[i]);
        }
      } else {
        exist[-nums[i] + 1000] = true;
        if (exist[-nums[i]]) {
          answer = max(answer, -nums[i]);
        }
      }
    }
    return answer;
  }
};
