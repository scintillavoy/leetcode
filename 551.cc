#include <string>
using namespace std;

class Solution {
 public:
  bool checkRecord(string s) {
    int absent_count = 0;
    int late_consecutive_count = 0;
    for (const auto c : s) {
      switch (c) {
        case 'A':
          late_consecutive_count = 0;
          ++absent_count;
          if (absent_count >= 2) {
            return false;
          }
          break;
        case 'L':
          ++late_consecutive_count;
          if (late_consecutive_count >= 3) {
            return false;
          }
          break;
        case 'P':
          late_consecutive_count = 0;
          break;
      }
    }
    return true;
  }
};
