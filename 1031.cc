#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    int n = nums.size();
    vector<int> prefix_sum(n + 1);
    for (int i = 1; i < prefix_sum.size(); ++i) {
      prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
    }
    return max(max_sum(prefix_sum, firstLen, secondLen),
               max_sum(prefix_sum, secondLen, firstLen));
  }

 private:
  int max_sum(vector<int>& prefix_sum, int firstLen, int secondLen) {
    int result = 0;
    int max_sum_of_first = 0;
    for (int i = firstLen + secondLen; i < prefix_sum.size(); ++i) {
      max_sum_of_first =
          max(max_sum_of_first,
              prefix_sum[i - secondLen] - prefix_sum[i - secondLen - firstLen]);
      result = max(
          result, max_sum_of_first + prefix_sum[i] - prefix_sum[i - secondLen]);
    }
    return result;
  }
};
