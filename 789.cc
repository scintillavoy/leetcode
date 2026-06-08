#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    int distance = abs(target[0]) + abs(target[1]);
    for (const auto& ghost : ghosts) {
      if (abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) <= distance) {
        return false;
      }
    }
    return true;
  }
};
