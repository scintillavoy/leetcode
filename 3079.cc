#include <vector>
using namespace std;

class Solution {
 public:
  int sumOfEncryptedInt(vector<int>& nums) {
    int sum = 0;
    for (auto num : nums) {
      int max_digit = 0;
      int num_of_digits = 0;
      while (num > 0) {
        max_digit = max(max_digit, num % 10);
        num /= 10;
        ++num_of_digits;
      }
      while (num_of_digits > 0) {
        num = num * 10 + max_digit;
        --num_of_digits;
      }
      sum += num;
    }
    return sum;
  }
};
