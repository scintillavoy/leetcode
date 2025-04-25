#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  int minimumChairs(string s) {
    int max_count = 0;
    int current_count = 0;
    for (const auto c : s) {
      if (c == 'E') {
        ++current_count;
        max_count = max(max_count, current_count);
      } else {
        --current_count;
      }
    }
    return max_count;
  }
};
