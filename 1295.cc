#include <vector>
using namespace std;

class Solution {
 public:
  int findNumbers(vector<int>& nums) {
    int result = 0;
    for (auto num : nums) {
      int num_of_digits = 0;
      while (num > 0) {
        num /= 10;
        ++num_of_digits;
      }
      if (num_of_digits % 2 == 0) {
        ++result;
      }
    }
    return result;
  }
};
