#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> shuffled(n * 2);
    for (int i = 0; i < n; ++i) {
      shuffled[i * 2] = nums[i];
      shuffled[i * 2 + 1] = nums[i + n];
    }
    return shuffled;
  }
};
