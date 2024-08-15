#include <vector>
using namespace std;

class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    int fives = 0, tens = 0;
    for (const auto bill : bills) {
      switch (bill) {
        case 5:
          ++fives;
          break;
        case 10:
          if (fives <= 0) {
            return false;
          }
          --fives;
          ++tens;
          break;
        case 20:
          if (tens >= 1 && fives >= 1) {
            --tens;
            --fives;
          } else if (fives >= 3) {
            fives -= 3;
          } else {
            return false;
          }
          break;
      }
    }
    return true;
  }
};
