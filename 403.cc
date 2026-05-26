#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canCross(vector<int>& stones) {
    int n = stones.size();
    unordered_map<int, unordered_set<int>> prev_jumps;
    for (const auto stone : stones) {
      prev_jumps[stone] = unordered_set<int>();
    }
    prev_jumps[0].insert(0);
    for (const auto stone : stones) {
      for (const auto prev_jump : prev_jumps[stone]) {
        for (int i = -1; i <= 1; ++i) {
          int jump = prev_jump + i;
          if (jump > 0 && prev_jumps.contains(stone + jump)) {
            prev_jumps[stone + jump].insert(jump);
          }
        }
      }
    }
    return !prev_jumps[stones.back()].empty();
  }
};
