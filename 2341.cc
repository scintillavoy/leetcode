#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> numberOfPairs(vector<int>& nums) {
    unordered_map<int, int> counts;
    for (const auto num : nums) {
      ++counts[num];
    }
    int num_of_pairs = 0;
    int num_of_leftovers = 0;
    for (const auto [_, count] : counts) {
      num_of_pairs += count / 2;
      num_of_leftovers += count % 2;
    }
    return {num_of_pairs, num_of_leftovers};
  }
};
