#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  int minTotalDistance(vector<vector<int>>& grid) {
    vector<vector<int>> coordinates(2);
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == 1) {
          coordinates[0].push_back(i);
          coordinates[1].push_back(j);
        }
      }
    }
    vector<int> medians(2);
    for (int i = 0; i < medians.size(); ++i) {
      nth_element(coordinates[i].begin(),
                  coordinates[i].begin() + coordinates[i].size() / 2,
                  coordinates[i].end());
      medians[i] = coordinates[i][coordinates[i].size() / 2];
    }
    int total_distance = 0;
    for (int i = 0; i < coordinates.size(); ++i) {
      for (int j = 0; j < coordinates[i].size(); ++j) {
        total_distance += abs(medians[i] - coordinates[i][j]);
      }
    }
    return total_distance;
  }
};
