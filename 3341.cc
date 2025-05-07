#include <algorithm>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
  int minTimeToReach(vector<vector<int>>& moveTime) {
    int m = moveTime.size();
    int n = moveTime[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
      auto [arrival_time, x, y] = pq.top();
      pq.pop();
      if (visited[x][y]) {
        continue;
      }
      visited[x][y] = true;
      if (x == m - 1 && y == n - 1) {
        return arrival_time;
      }
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2]) {
          continue;
        }
        pq.push({max(arrival_time, moveTime[x2][y2]) + 1, x2, y2});
      }
    }
    return -1;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
