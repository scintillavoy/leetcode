#include <cmath>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int result = -1;
    int min_distance = numeric_limits<int>::max();
    for (int i = 0; i < points.size(); ++i) {
      if (points[i][0] == x || points[i][1] == y) {
        int current_distance = abs(points[i][0] - x) + abs(points[i][1] - y);
        if (current_distance < min_distance) {
          min_distance = current_distance;
          result = i;
        }
      }
    }
    return result;
  }
};
