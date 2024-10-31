#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  long long minimumTotalDistance(vector<int>& robot,
                                 vector<vector<int>>& factory) {
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());
    vector<int> factory_positions;
    for (const auto& f : factory) {
      for (int i = f[1]; i > 0; --i) {
        factory_positions.push_back(f[0]);
      }
    }
    vector<long long> min_distances(factory_positions.size() + 1);
    for (int i = robot.size() - 1; i >= 0; --i) {
      vector<long long> next_min_distances(factory_positions.size() + 1);
      next_min_distances.back() = numeric_limits<long long>::max();
      for (int j = factory_positions.size() - 1; j >= 0; --j) {
        long long distance_fixed;
        if (min_distances[j + 1] == numeric_limits<long long>::max()) {
          distance_fixed = numeric_limits<long long>::max();
        } else {
          distance_fixed =
              abs(robot[i] - factory_positions[j]) + min_distances[j + 1];
        }
        long long distance_skipped = next_min_distances[j + 1];
        next_min_distances[j] = min(distance_fixed, distance_skipped);
      }
      min_distances = next_min_distances;
    }
    return min_distances.front();
  }
};
