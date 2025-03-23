#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  int maxPower(string s) {
    int max_power = 1;
    int curr_power = 1;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i - 1] == s[i]) {
        ++curr_power;
        max_power = max(max_power, curr_power);
      } else {
        curr_power = 1;
      }
    }
    return max_power;
  }
};
