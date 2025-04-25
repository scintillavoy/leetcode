#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    long long result = 0;
    unordered_map<int, int> prefix_counts;
    prefix_counts[0] = 1;
    int current_count = 0;
    for (const auto num : nums) {
      if (num % modulo == k) {
        current_count = (current_count + 1) % modulo;
      }
      result += prefix_counts[(current_count - k + modulo) % modulo];
      ++prefix_counts[current_count];
    }
    return result;
  }
};
