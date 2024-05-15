#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfCleanRooms(vector<vector<int>>& room) {
    int m = room.size();
    int n = room[0].size();
    vector<vector<vector<bool>>> visited(
        m, vector<vector<bool>>(n, vector<bool>(4)));
    visited[0][0][0] = true;
    int x = 0, y = 0, dir = 0;
    int answer = 1;
    while (true) {
      int x2, y2, rotation;
      for (rotation = 0; rotation < 4; ++rotation) {
        x2 = x + dx[dir];
        y2 = y + dy[dir];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || room[x2][y2] == 1) {
          dir = (dir + 1) % 4;
        } else {
          break;
        }
      }
      if (rotation == 4 || visited[x2][y2][dir]) {
        break;
      }
      if (!visited[x2][y2][0] && !visited[x2][y2][1] && !visited[x2][y2][2] &&
          !visited[x2][y2][3]) {
        ++answer;
      }
      visited[x2][y2][dir] = true;
      x = x2;
      y = y2;
    }
    return answer;
  }

 private:
  const int dx[4] = {0, 1, 0, -1};
  const int dy[4] = {1, 0, -1, 0};
};
