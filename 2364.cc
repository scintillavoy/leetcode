#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  long long countBadPairs(vector<int>& nums) {
    long long num_of_bad_pairs = 0;
    unordered_map<int, int> counts;
    for (int i = 0; i < nums.size(); ++i) {
      num_of_bad_pairs += i - counts[i - nums[i]];
      ++counts[i - nums[i]];
    }
    return num_of_bad_pairs;
  }
};
