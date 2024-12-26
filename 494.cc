#include <vector>
using namespace std;

#define MAX 2000

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    vector<int> possible_ways(MAX + 1);
    possible_ways[1000] = 1;
    for (const auto num : nums) {
      vector<int> next_possible_ways(MAX + 1);
      for (int i = 0; i <= MAX; ++i) {
        if (possible_ways[i] > 0) {
          next_possible_ways[i + num] += possible_ways[i];
          next_possible_ways[i - num] += possible_ways[i];
        }
      }
      possible_ways = next_possible_ways;
    }
    return possible_ways[target + 1000];
  }
};
