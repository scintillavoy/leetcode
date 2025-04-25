#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximizeSum(vector<int>& nums, int k) {
    int max_num = *max_element(nums.begin(), nums.end());
    return (max_num + k - 1) * (max_num + k) / 2 - (max_num - 1) * max_num / 2;
  }
};
