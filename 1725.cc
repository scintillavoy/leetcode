#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int countGoodRectangles(vector<vector<int>>& rectangles) {
    int max_length = 0;
    int count = 0;
    for (const auto& rectangle : rectangles) {
      int length = min(rectangle[0], rectangle[1]);
      if (length > max_length) {
        max_length = length;
        count = 1;
      } else if (length == max_length) {
        ++count;
      }
    }
    return count;
  }
};
