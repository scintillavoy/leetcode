#include <string>
#include <utility>
#include <vector>
using namespace std;

struct Coordinate {
  int x;
  int y;
  int z;
};

inline bool operator==(const Coordinate &lhs, const Coordinate &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

inline bool operator!=(const Coordinate &lhs, const Coordinate &rhs) {
  return !(lhs == rhs);
}

class Solution {
 public:
  int regionsBySlashes(vector<string> &grid) {
    int n = grid.size();
    parents = vector<vector<vector<Coordinate>>>(
        n, vector<vector<Coordinate>>(n, vector<Coordinate>(4)));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < 4; ++k) {
          parents[i][j][k] = {i, j, k};
        }
      }
    }
    ranks =
        vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(4)));
    int num_of_regions = n * n * 4;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i > 0) {
          num_of_regions -= union_set({i, j, 0}, {i - 1, j, 2});
        }
        if (j > 0) {
          num_of_regions -= union_set({i, j, 3}, {i, j - 1, 1});
        }
        if (grid[i][j] != '/') {
          num_of_regions -= union_set({i, j, 0}, {i, j, 1});
          num_of_regions -= union_set({i, j, 2}, {i, j, 3});
        }
        if (grid[i][j] != '\\') {
          num_of_regions -= union_set({i, j, 0}, {i, j, 3});
          num_of_regions -= union_set({i, j, 1}, {i, j, 2});
        }
      }
    }
    return num_of_regions;
  }

 private:
  vector<vector<vector<Coordinate>>> parents;
  vector<vector<vector<int>>> ranks;

  Coordinate find_set(Coordinate c) {
    if (parents[c.x][c.y][c.z] != c) {
      parents[c.x][c.y][c.z] = find_set(parents[c.x][c.y][c.z]);
    }
    return parents[c.x][c.y][c.z];
  }

  int union_set(Coordinate c1, Coordinate c2) {
    c1 = find_set(c1);
    c2 = find_set(c2);
    if (c1 == c2) {
      return 0;
    }
    if (ranks[c1.x][c1.y][c1.z] > ranks[c2.x][c2.y][c2.z]) {
      swap(c1, c2);
    } else if (ranks[c1.x][c1.y][c1.z] == ranks[c2.x][c2.y][c2.z]) {
      ++ranks[c2.x][c2.y][c2.z];
    }
    parents[c1.x][c1.y][c1.z] = c2;
    return 1;
  }
};
