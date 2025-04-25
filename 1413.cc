#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minStartValue(vector<int>& nums) {
    int min_start_value = 1;
    int current_sum = 0;
    for (const auto num : nums) {
      current_sum += num;
      min_start_value = max(min_start_value, 1 - current_sum);
    }
    return min_start_value;
  }
};
