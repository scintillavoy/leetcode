#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> operations;
    int target_index = 0;
    for (int i = 1; i <= n; ++i) {
      operations.push_back("Push");
      if (i == target[target_index]) {
        ++target_index;
        if (target_index == target.size()) {
          break;
        }
      } else {
        operations.push_back("Pop");
      }
    }
    return operations;
  }
};
