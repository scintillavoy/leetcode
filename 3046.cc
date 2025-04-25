#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isPossibleToSplit(vector<int>& nums) {
    unordered_map<int, int> counts;
    for (const auto num : nums) {
      ++counts[num];
      if (counts[num] > 2) {
        return false;
      }
    }
    return true;
  }
};
