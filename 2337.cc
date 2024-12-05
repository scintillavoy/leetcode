#include <string>
using namespace std;

class Solution {
 public:
  bool canChange(string start, string target) {
    int start_index = 0, target_index = 0;
    while (start_index < start.size() || target_index < target.size()) {
      while (start_index < start.size() && start[start_index] == '_') {
        ++start_index;
      }
      while (target_index < target.size() && target[target_index] == '_') {
        ++target_index;
      }
      if (start_index == start.size() || target_index == target.size()) {
        return start_index == start.size() && target_index == target.size();
      }
      if (start[start_index] != target[target_index] ||
          (start[start_index] == 'L' && start_index < target_index) ||
          (start[start_index] == 'R' && start_index > target_index)) {
        return false;
      }
      ++start_index;
      ++target_index;
    }
    return true;
  }
};
