#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minOperations(vector<string>& logs) {
    int depth = 0;
    for (const auto& log : logs) {
      if (log == "./") {
        continue;
      } else if (log == "../") {
        depth = max(0, depth - 1);
      } else {
        ++depth;
      }
    }
    return depth;
  }
};
