#include <string>
using namespace std;

class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int number = 0;
    for (const auto ch : columnTitle) {
      number = number * 26 - 'A' + ch + 1;
    }
    return number;
  }
};
