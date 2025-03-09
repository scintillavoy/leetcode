#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int num_of_alternating_groups = 0;
    int left = 0;
    for (int right = 1; right < colors.size() + k - 1; ++right) {
      if (colors[right % colors.size()] ==
          colors[(right - 1) % colors.size()]) {
        left = right;
      }
      if (right - left + 1 == k) {
        ++num_of_alternating_groups;
        ++left;
      }
    }
    return num_of_alternating_groups;
  }
};
