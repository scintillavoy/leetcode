#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> divideArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result(nums.size() / 3, vector<int>(3));
    int index = 0;
    for (int i = 0; i < result.size(); ++i) {
      for (int j = 0; j < result[0].size(); ++j) {
        result[i][j] = nums[index];
        ++index;
        if (result[i][j] - result[i][0] > k) {
          return {};
        }
      }
    }
    return result;
  }
};
