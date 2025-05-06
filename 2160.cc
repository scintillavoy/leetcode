#include <vector>
using namespace std;

class Solution {
 public:
  int minimumSum(int num) {
    vector<int> digit_counts(10);
    while (num > 0) {
      ++digit_counts[num % 10];
      num /= 10;
    }
    int min_sum = 0;
    int current_digit = 0;
    for (int i = 0; i < 4; ++i) {
      while (digit_counts[current_digit] == 0) {
        ++current_digit;
      }
      min_sum += current_digit;
      --digit_counts[current_digit];
      if (i == 1) {
        min_sum *= 10;
      }
    }
    return min_sum;
  }
};
