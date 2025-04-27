#include <vector>
using namespace std;

class Solution {
 public:
  int getMinDistance(vector<int>& nums, int target, int start) {
    int min_distance = 0;
    while (true) {
      if (start - min_distance >= 0 && nums[start - min_distance] == target ||
          start + min_distance < nums.size() &&
              nums[start + min_distance] == target) {
        return min_distance;
      }
      ++min_distance;
    }
    return -1;
  }
};
