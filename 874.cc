#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    unordered_map<int, unordered_set<int>> obstacle_map;
    for (const auto& obstacle : obstacles) {
      obstacle_map[obstacle[0]].insert(obstacle[1]);
    }
    int x = 0;
    int y = 0;
    int max_distance = 0;
    for (const auto command : commands) {
      switch (command) {
        case -2:
          direction = (direction + 3) % 4;
          break;
        case -1:
          direction = (direction + 1) % 4;
          break;
        default:
          for (int i = 0; i < command; ++i) {
            int x2 = x + dx[direction];
            int y2 = y + dy[direction];
            if (obstacle_map[x2].contains(y2)) {
              break;
            }
            x = x2;
            y = y2;
            max_distance = max(max_distance, x * x + y * y);
          }
      }
    }
    return max_distance;
  }

 private:
  const int dx[4] = {0, 1, 0, -1};
  const int dy[4] = {1, 0, -1, 0};

  int direction = 0;
};
