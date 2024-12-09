#include <vector>
using namespace std;

class Solution {
 public:
  vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> prefix_sum_of_same_parities(nums.size());
    for (int i = 1; i < nums.size(); ++i) {
      prefix_sum_of_same_parities[i] = prefix_sum_of_same_parities[i - 1];
      if (nums[i - 1] % 2 == nums[i] % 2) {
        ++prefix_sum_of_same_parities[i];
      }
    }
    vector<bool> result(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      result[i] = prefix_sum_of_same_parities[queries[i][1]] -
                      prefix_sum_of_same_parities[queries[i][0]] ==
                  0;
    }
    return result;
  }
};
