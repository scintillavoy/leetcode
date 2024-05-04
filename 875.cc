#include <vector>
using namespace std;

class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = 1e9;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      long long hours = 0;
      for (const auto& pile : piles) {
        hours += pile / mid;
        if (pile % mid != 0) {
          ++hours;
        }
      }
      if (hours <= h) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
