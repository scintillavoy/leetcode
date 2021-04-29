#include <queue>
#include <utility>
#include <vector>
using namespace std;

// Multi-source BFS
class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    vector<vector<int>> height(isWater.size(),
                               vector<int>(isWater[0].size(), -1));
    queue<pair<int, int>> bfs;
    for (int i = 0; i < isWater.size(); ++i) {
      for (int j = 0; j < isWater[0].size(); ++j) {
        if (isWater[i][j] == 0) continue;
        height[i][j] = 0;
        bfs.push({i, j});
      }
    }

    vector<int> dir{0, 1, 0, -1, 0};
    while (!bfs.empty()) {
      pair<int, int> curr = bfs.front(); bfs.pop();
      for (int i = 0; i < 4; ++i) {
        pair<int, int> next{curr.first + dir[i], curr.second + dir[i + 1]};
        if (0 <= next.first && next.first < isWater.size() &&
            0 <= next.second && next.second < isWater[0].size() &&
            height[next.first][next.second] == -1) {
          height[next.first][next.second] = height[curr.first][curr.second] + 1;
          bfs.push(next);
        }
      }
    }

    return height;
  }
};

int main() { return 0; }
