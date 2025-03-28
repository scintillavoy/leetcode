#include <algorithm>
#include <functional>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    int m = grid.size();
    int n = grid[0].size();
    vector<pair<int, int>> query_index_pairs(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      query_index_pairs[i] = {queries[i], i};
    }
    sort(query_index_pairs.begin(), query_index_pairs.end());
    vector<vector<bool>> visited(m, vector<bool>(n));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    visited[0][0] = true;
    pq.push({grid[0][0], 0, 0});
    int current_point = 0;
    vector<int> points(queries.size());
    for (const auto [query, index] : query_index_pairs) {
      while (!pq.empty() && get<0>(pq.top()) < query) {
        auto [value, x, y] = pq.top();
        pq.pop();
        ++current_point;
        for (int i = 0; i < 4; ++i) {
          int x2 = x + dx[i];
          int y2 = y + dy[i];
          if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2]) {
            continue;
          }
          visited[x2][y2] = true;
          pq.push({grid[x2][y2], x2, y2});
        }
      }
      points[index] = current_point;
    }
    return points;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
