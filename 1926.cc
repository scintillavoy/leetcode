#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size();
    int n = maze[0].size();
    maze[entrance[0]][entrance[1]] = '+';
    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});
    int steps = 1;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        auto [x, y] = q.front();
        q.pop();
        for (int j = 0; j < 4; ++j) {
          int x2 = x + dx[j];
          int y2 = y + dy[j];
          if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || maze[x2][y2] == '+') {
            continue;
          }
          if (x2 == 0 || x2 == m - 1 || y2 == 0 || y2 == n - 1) {
            return steps;
          }
          maze[x2][y2] = '+';
          q.push({x2, y2});
        }
      }
      ++steps;
    }
    return -1;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
