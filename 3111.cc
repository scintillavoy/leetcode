#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
    sort(points.begin(), points.end());
    int num_of_rectangles = 1;
    int last_covered = points[0][0] + w;
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] > last_covered) {
        ++num_of_rectangles;
        last_covered = points[i][0] + w;
      }
    }
    return num_of_rectangles;
  }
};
