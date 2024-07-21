#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                  vector<vector<int>>& colConditions) {
    vector<pair<int, int>> number_to_row_col(k + 1);
    if (!find_row_col(true, k, rowConditions, number_to_row_col) ||
        !find_row_col(false, k, colConditions, number_to_row_col)) {
      return {};
    }
    vector<vector<int>> result(k, vector<int>(k));
    for (int i = 1; i <= k; ++i) {
      auto [row, col] = number_to_row_col[i];
      result[row][col] = i;
    }
    return result;
  }

 private:
  bool find_row_col(bool is_row, int k, vector<vector<int>>& conditions,
                    vector<pair<int, int>>& number_to_row_col) {
    vector<vector<int>> graph(k + 1);
    vector<int> in_degree(k + 1);
    for (const auto& condition : conditions) {
      graph[condition[0]].push_back(condition[1]);
      ++in_degree[condition[1]];
    }
    queue<int> q;
    for (int i = 1; i <= k; ++i) {
      if (in_degree[i] == 0) {
        q.push(i);
      }
    }
    int finished = 0;
    int curr_row_col = 0;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      ++finished;
      if (is_row) {
        number_to_row_col[curr].first = curr_row_col;
      } else {
        number_to_row_col[curr].second = curr_row_col;
      }
      ++curr_row_col;
      for (const auto adj : graph[curr]) {
        --in_degree[adj];
        if (in_degree[adj] == 0) {
          q.push(adj);
        }
      }
    }
    return finished == k;
  }
};
