#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfPoints(vector<vector<int>>& nums) {
    sort(nums.begin(), nums.end());
    int result = 0;
    int last_point = -1;
    for (const auto& num : nums) {
      if (num[1] <= last_point) {
        continue;
      }
      result += num[1] - max(num[0] - 1, last_point);
      last_point = num[1];
    }
    return result;
  }
};
