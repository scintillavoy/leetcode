#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> counts;
    for (const auto num : nums) {
      ++counts[num];
    }
    int max_length = 0;
    for (const auto [num, count] : counts) {
      if (counts.contains(num + 1)) {
        max_length = max(max_length, count + counts[num + 1]);
      }
    }
    return max_length;
  }
};
