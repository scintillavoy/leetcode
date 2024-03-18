#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    int count = 1;
    int right = points[0][1];
    for (int i = 1; i < points.size(); ++i) {
      if (right < points[i][0]) {
        ++count;
        right = points[i][1];
      } else {
        right = min(right, points[i][1]);
      }
    }
    return count;
  }
};
