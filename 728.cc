#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> result;
    for (int i = left; i <= right; ++i) {
      if (is_self_dividing_number(i)) {
        result.push_back(i);
      }
    }
    return result;
  }

 private:
  bool is_self_dividing_number(int number) {
    int current_number = number;
    while (current_number > 0) {
      if (current_number % 10 == 0 || number % (current_number % 10) != 0) {
        return false;
      }
      current_number /= 10;
    }
    return true;
  }
};
