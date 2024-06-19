#include <vector>
using namespace std;

class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int days) {
    int start = 1, end = 0;
    for (const auto weight : weights) {
      start = max(start, weight);
      end += weight;
    }
    while (start <= end) {
      int mid = start + (end - start) / 2;
      int days_needed = 1;
      int curr_weight = 0;
      for (const auto weight : weights) {
        if (curr_weight + weight > mid) {
          ++days_needed;
          curr_weight = 0;
        }
        curr_weight += weight;
      }
      if (days_needed <= days) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};
