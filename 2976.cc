#include <limits>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  long long minimumCost(string source, string target, vector<char>& original,
                        vector<char>& changed, vector<int>& cost) {
    vector<vector<int>> distances(
        26, vector<int>(26, numeric_limits<int>::max() / 2));
    for (int i = 0; i < original.size(); ++i) {
      distances[original[i] - 'a'][changed[i] - 'a'] =
          min(distances[original[i] - 'a'][changed[i] - 'a'], cost[i]);
    }
    for (int i = 0; i < 26; ++i) {
      distances[i][i] = 0;
    }
    for (int k = 0; k < 26; ++k) {
      for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
          if (distances[i][j] > distances[i][k] + distances[k][j]) {
            distances[i][j] = distances[i][k] + distances[k][j];
          }
        }
      }
    }
    long long min_cost = 0;
    for (int i = 0; i < source.size(); ++i) {
      int cost = distances[source[i] - 'a'][target[i] - 'a'];
      if (cost == numeric_limits<int>::max() / 2) {
        return -1;
      }
      min_cost += cost;
    }
    return min_cost;
  }
};
