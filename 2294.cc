#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int partitionArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int num_of_subsequences = 1;
    int max_num = nums.front() + k;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > max_num) {
        ++num_of_subsequences;
        max_num = nums[i] + k;
      }
    }
    return num_of_subsequences;
  }
};
