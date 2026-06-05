#include <string>
using namespace std;

class Solution {
 public:
  bool canTransform(string start, string result) {
    int i = 0;
    int j = 0;
    while (i < start.size() || j < result.size()) {
      while (i < start.size() && start[i] == 'X') {
        ++i;
      }
      while (j < result.size() && result[j] == 'X') {
        ++j;
      }
      if (i >= start.size() || j >= result.size()) {
        break;
      }
      if (start[i] != result[j]) {
        return false;
      }
      if (start[i] == 'L' && i < j) {
        return false;
      }
      if (start[i] == 'R' && j < i) {
        return false;
      }
      ++i;
      ++j;
    }
    return i == j;
  }
};
