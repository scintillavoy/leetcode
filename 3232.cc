#include <vector>
using namespace std;

class Solution {
 public:
  bool canAliceWin(vector<int>& nums) {
    int sum_of_single_digits = 0;
    int sum_of_double_digits = 0;
    for (const auto num : nums) {
      if (num < 10) {
        sum_of_single_digits += num;
      } else {
        sum_of_double_digits += num;
      }
    }
    return sum_of_single_digits != sum_of_double_digits;
  }
};
