#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> counts;
    for (const auto num : nums) {
      ++counts[num];
    }
    int max_count = 0;
    int result = 0;
    for (const auto [_, count] : counts) {
      if (max_count == count) {
        result += count;
      } else if (max_count < count) {
        max_count = count;
        result = count;
      }
    }
    return result;
  }
};
