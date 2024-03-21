#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int start = 0, end = height.size() - 1;
    int max_amount = 0;
    while (start < end) {
      max_amount =
          max(max_amount, (end - start) * min(height[start], height[end]));
      if (height[start] < height[end]) {
        ++start;
      } else {
        --end;
      }
    }
    return max_amount;
  }
};
