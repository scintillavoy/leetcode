#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int answer = 0;
    int max_index = 0;
    int next_max_index = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (max_index >= nums.size() - 1) {
        break;
      }
      if (i > max_index) {
        ++answer;
        max_index = next_max_index;
      }
      next_max_index = max(next_max_index, i + nums[i]);
    }
    return answer;
  }
};
