#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> distances(
        n, vector<int>(n, numeric_limits<int>::max() / 2));
    for (int i = 0; i < n; ++i) {
      distances[i][i] = 0;
    }
    for (const auto& edge : edges) {
      distances[edge[0]][edge[1]] = edge[2];
      distances[edge[1]][edge[0]] = edge[2];
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (distances[i][j] > distances[i][k] + distances[k][j]) {
            distances[i][j] = distances[i][k] + distances[k][j];
          }
        }
      }
    }
    int min_neighbors = numeric_limits<int>::max();
    int result = -1;
    for (int i = 0; i < n; ++i) {
      int neighbors = 0;
      for (int j = 0; j < n; ++j) {
        if (i == j) {
          continue;
        }
        if (distances[i][j] <= distanceThreshold) {
          ++neighbors;
        }
      }
      if (min_neighbors >= neighbors) {
        min_neighbors = neighbors;
        result = i;
      }
    }
    return result;
  }
};
