#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_area = 0;
    stack<pair<int, int>> dfs_queue;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          dfs_queue.push({i, j});
          int area = 0;
          while (!dfs_queue.empty()) {
            pair<int, int> curr = dfs_queue.top();
            dfs_queue.pop();
            if (grid[curr.first][curr.second] != 1) {
              continue;
            }
            grid[curr.first][curr.second] = -1;
            ++area;
            // Better way to check 4 directions
            // vector<int> dir{-1,0,1,0,-1};
            // grid[i+dir[k]][j+dir[k+1]];
            if (curr.first - 1 >= 0 && grid[curr.first - 1][curr.second] == 1) {
              dfs_queue.push({curr.first - 1, curr.second});
            }
            if (curr.second - 1 >= 0 &&
                grid[curr.first][curr.second - 1] == 1) {
              dfs_queue.push({curr.first, curr.second - 1});
            }
            if (curr.first + 1 < grid.size() &&
                grid[curr.first + 1][curr.second] == 1) {
              dfs_queue.push({curr.first + 1, curr.second});
            }
            if (curr.second + 1 < grid[0].size() &&
                grid[curr.first][curr.second + 1] == 1) {
              dfs_queue.push({curr.first, curr.second + 1});
            }
          }
          max_area = max(max_area, area);
        }
      }
    }
    return max_area;
  }
};

int main() { return 0; }
