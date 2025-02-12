#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumSum(vector<int>& nums) {
    int max_sum = -1;
    unordered_map<int, int> sum_of_digits_to_max_num;
    for (const auto num : nums) {
      int sum_of_digits = 0;
      for (int i = num; i > 0; i /= 10) {
        sum_of_digits += i % 10;
      }
      if (sum_of_digits_to_max_num.contains(sum_of_digits)) {
        max_sum = max(max_sum, sum_of_digits_to_max_num[sum_of_digits] + num);
      }
      sum_of_digits_to_max_num[sum_of_digits] =
          max(sum_of_digits_to_max_num[sum_of_digits], num);
    }
    return max_sum;
  }
};
