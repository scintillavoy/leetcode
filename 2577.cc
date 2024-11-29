#include <functional>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumTime(vector<vector<int>>& grid) {
    if (grid[0][1] > 1 && grid[1][0] > 1) {
      return -1;
    }
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> min_times(m,
                                  vector<int>(n, numeric_limits<int>::max()));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    min_times[0][0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
      auto [curr_min_time, x, y] = pq.top();
      pq.pop();
      if (min_times[x][y] < curr_min_time) {
        continue;
      }
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n) {
          continue;
        }
        int next_min_time;
        if (curr_min_time + 1 >= grid[x2][y2]) {
          next_min_time = curr_min_time + 1;
        } else {
          next_min_time = grid[x2][y2];
          if (curr_min_time % 2 == grid[x2][y2] % 2) {
            ++next_min_time;
          }
        }
        if (min_times[x2][y2] > next_min_time) {
          min_times[x2][y2] = next_min_time;
          pq.push({min_times[x2][y2], x2, y2});
        }
      }
    }
    return min_times.back().back();
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
