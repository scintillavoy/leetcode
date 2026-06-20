#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minMoves(vector<int>& nums) {
    int sum = 0;
    int max_num = 0;
    for (const auto num : nums) {
      sum += num;
      max_num = max(max_num, num);
    }
    return max_num * nums.size() - sum;
  }
};
