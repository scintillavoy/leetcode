#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> sumEvenAfterQueries(vector<int>& nums,
                                  vector<vector<int>>& queries) {
    int even_sum = 0;
    for (const auto num : nums) {
      if (num % 2 == 0) {
        even_sum += num;
      }
    }
    vector<int> result(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      int val = queries[i][0];
      int index = queries[i][1];
      if (nums[index] % 2 == 0) {
        even_sum -= nums[index];
      }
      nums[index] += val;
      if (nums[index] % 2 == 0) {
        even_sum += nums[index];
      }
      result[i] = even_sum;
    }
    return result;
  }
};
