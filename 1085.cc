#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int sumOfDigits(vector<int>& nums) {
    int min_num = *min_element(nums.begin(), nums.end());
    int sum_of_digits = 0;
    while (min_num > 0) {
      sum_of_digits += min_num % 10;
      min_num /= 10;
    }
    return 1 - sum_of_digits % 2;
  }
};
