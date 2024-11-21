#include <vector>
using namespace std;

class Solution {
 public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards,
                     vector<vector<int>>& walls) {
    vector<vector<cell>> grid(m, vector<cell>(n, cell::unguarded));
    int num_of_unguarded = m * n;
    for (const auto& guard : guards) {
      grid[guard[0]][guard[1]] = cell::guard;
      --num_of_unguarded;
    }
    for (const auto& wall : walls) {
      grid[wall[0]][wall[1]] = cell::wall;
      --num_of_unguarded;
    }
    for (const auto& guard : guards) {
      for (int i = 0; i < 4; ++i) {
        int x = guard[0] + dx[i];
        int y = guard[1] + dy[i];
        while (x >= 0 && x < m && y >= 0 && y < n &&
               (grid[x][y] == cell::unguarded || grid[x][y] == cell::guarded)) {
          if (grid[x][y] == cell::unguarded) {
            grid[x][y] = cell::guarded;
            --num_of_unguarded;
          }
          x += dx[i];
          y += dy[i];
        }
      }
    }
    return num_of_unguarded;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  enum struct cell {
    unguarded,
    guarded,
    guard,
    wall,
  };
};
