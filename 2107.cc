#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int shareCandies(vector<int>& candies, int k) {
    unordered_map<int, int> counts;
    for (const auto candy : candies) {
      ++counts[candy];
    }
    int max_num_of_flavors = 0;
    int left = 0;
    for (int right = 0; right < candies.size(); ++right) {
      --counts[candies[right]];
      if (counts[candies[right]] == 0) {
        counts.erase(candies[right]);
      }
      if (right - left + 1 > k) {
        ++counts[candies[left]];
        ++left;
      }
      if (right - left + 1 == k) {
        max_num_of_flavors = max(max_num_of_flavors, (int)counts.size());
      }
    }
    return max_num_of_flavors;
  }
};
