#include <string>
using namespace std;

class Solution {
 public:
  int countSymmetricIntegers(int low, int high) {
    int count = 0;
    for (int i = low; i <= high; ++i) {
      string num = to_string(i);
      if (num.size() % 2 == 1) {
        continue;
      }
      int left_sum = 0;
      for (int j = 0; j < num.size() / 2; ++j) {
        left_sum += num[j] - '0';
      }
      int right_sum = 0;
      for (int j = num.size() / 2; j < num.size(); ++j) {
        right_sum += num[j] - '0';
      }
      if (left_sum == right_sum) {
        ++count;
      }
    }
    return count;
  }
};
