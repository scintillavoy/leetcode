#include <vector>
using namespace std;

class Solution {
 public:
  int returnToBoundaryCount(vector<int>& nums) {
    int position = 0;
    int count = 0;
    for (const auto num : nums) {
      position += num;
      if (position == 0) {
        ++count;
      }
    }
    return count;
  }
};
