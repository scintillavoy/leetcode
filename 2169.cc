#include <utility>
using namespace std;

class Solution {
 public:
  int countOperations(int num1, int num2) {
    int count = 0;
    if (num1 < num2) {
      swap(num1, num2);
    }
    while (num2 != 0) {
      count += num1 / num2;
      int temp = num2;
      num2 = num1 % num2;
      num1 = temp;
    }
    return count;
  }
};
