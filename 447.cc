#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int num_of_boomerangs = 0;
    for (int i = 0; i < points.size(); ++i) {
      unordered_map<int, int> distance_to_count;
      for (int j = 0; j < points.size(); ++j) {
        if (i == j) {
          continue;
        }
        int distance =
            (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) +
            (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
        ++distance_to_count[distance];
      }
      for (const auto [distance, count] : distance_to_count) {
        num_of_boomerangs += count * (count - 1);
      }
    }
    return num_of_boomerangs;
  }
};
