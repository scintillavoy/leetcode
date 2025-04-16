#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    int n = nums.size();
    long long num_of_good_subarrays = 0;
    unordered_map<int, int> num_counts;
    int num_of_pairs = 0;
    // Sliding window with range [start, end)
    int end = 0;
    for (int start = 0; start < n; ++start) {
      while (num_of_pairs < k) {
        if (end == n) {
          return num_of_good_subarrays;
        }
        num_of_pairs += num_counts[nums[end]];
        ++num_counts[nums[end]];
        ++end;
      }
      num_of_good_subarrays += n - end + 1;
      --num_counts[nums[start]];
      num_of_pairs -= num_counts[nums[start]];
    }
    return num_of_good_subarrays;
  }
};
