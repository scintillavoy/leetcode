#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumCount(vector<int>& nums) {
    int num_of_negatives =
        lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
    int num_of_positives =
        nums.end() - upper_bound(nums.begin(), nums.end(), 0);
    return max(num_of_negatives, num_of_positives);
  }
};
