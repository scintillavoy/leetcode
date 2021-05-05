#include <algorithm>
#include <vector>
using namespace std;

// Time complexity: O(n)
class Solution {
 public:
  int jump(vector<int>& nums) {
    int res = 0;
    int prev_last = 0;
    int last = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      last = max(last, i + nums[i]);
      if (i == prev_last) {
        ++res;
        prev_last = last;
      }
    }
    return res;
  }
};

int main() { return 0; }
