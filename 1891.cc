#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxLength(vector<int>& ribbons, int k) {
    int start = 1, end = *max_element(ribbons.cbegin(), ribbons.cend());
    while (start <= end) {
      int mid = start + (end - start) / 2;
      int count = 0;
      for (const auto ribbon : ribbons) {
        count += ribbon / mid;
      }
      if (count < k) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return start - 1;
  }
};
