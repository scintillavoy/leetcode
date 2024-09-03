#include <string>
using namespace std;

class Solution {
 public:
  int getLucky(string s, int k) {
    int transformed = 0;
    for (const auto c : s) {
      int converted = c - 'a' + 1;
      while (converted > 0) {
        transformed += converted % 10;
        converted /= 10;
      }
    }
    for (int i = 1; i < k; ++i) {
      if (transformed < 10) {
        return transformed;
      }
      int next = 0;
      while (transformed > 0) {
        next += transformed % 10;
        transformed /= 10;
      }
      transformed = next;
    }
    return transformed;
  }
};
