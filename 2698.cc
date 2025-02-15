#include <string>
using namespace std;

class Solution {
 public:
  int punishmentNumber(int n) {
    int punishment_number = 0;
    for (int i = 1; i <= n; ++i) {
      if (can_be_partitioned(to_string(i * i), 0, 0, i)) {
        punishment_number += i * i;
      }
    }
    return punishment_number;
  }

 private:
  bool can_be_partitioned(const string &num, int index, int curr_num,
                          int remaining) {
    if (index == num.size()) {
      return remaining == curr_num;
    }
    curr_num = curr_num * 10 + num[index] - '0';
    return can_be_partitioned(num, index + 1, 0, remaining - curr_num) ||
           can_be_partitioned(num, index + 1, curr_num, remaining);
  }
};
