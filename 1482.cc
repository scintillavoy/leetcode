#include <vector>
using namespace std;

class Solution {
 public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    int left = 1, right = 1'000'000'000;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      int consecutive = 0;
      int bouquet = 0;
      for (int i = 0; i < bloomDay.size(); ++i) {
        if (bloomDay[i] <= mid) {
          ++consecutive;
          if (consecutive >= k) {
            consecutive = 0;
            ++bouquet;
          }
        } else {
          consecutive = 0;
        }
      }
      if (bouquet >= m) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return (left <= 1'000'000'000 ? left : -1);
  }
};
