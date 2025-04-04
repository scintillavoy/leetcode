#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int countKDifference(vector<int>& nums, int k) {
    unordered_map<int, int> num_counts;
    int total_count = 0;
    for (const auto num : nums) {
      total_count += num_counts[num + k] + num_counts[num - k];
      ++num_counts[num];
    }
    return total_count;
  }
};
