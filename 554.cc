#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    unordered_map<long long, int> counts;
    int max_count = 0;
    for (int i = 0; i < wall.size(); ++i) {
      long long sum = 0;
      for (int j = 0; j < wall[i].size() - 1; ++j) {
        sum += wall[i][j];
        ++counts[sum];
        max_count = max(max_count, counts[sum]);
      }
    }
    return wall.size() - max_count;
  }
};
