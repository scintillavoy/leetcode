#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int minElement(vector<int>& nums) {
    int min_element = numeric_limits<int>::max();
    for (auto num : nums) {
      int sum_of_digits = 0;
      while (num > 0) {
        sum_of_digits += num % 10;
        num /= 10;
      }
      min_element = min(min_element, sum_of_digits);
    }
    return min_element;
  }
};
