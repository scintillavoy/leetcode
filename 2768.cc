#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<long long> countBlackBlocks(int m, int n,
                                     vector<vector<int>>& coordinates) {
    vector<long long> answer(5);
    answer[0] = (long long)(m - 1) * (n - 1);
    auto hash = [](const pair<int, int>& a) { return a.first ^ a.second; };
    unordered_set<pair<int, int>, decltype(hash)> s;
    for (const auto& coordinate : coordinates) {
      int x = coordinate[0];
      int y = coordinate[1];
      for (int i = 0; i < 4; ++i) {
        int count = 0;
        bool valid = true;
        for (int j = 0; j < 3; ++j) {
          int x2 = x + dx[i][j];
          int y2 = y + dy[i][j];
          if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n) {
            valid = false;
            break;
          }
          if (s.count({x2, y2}) != 0) {
            ++count;
          }
        }
        if (!valid) {
          continue;
        }
        --answer[count];
        ++answer[count + 1];
      }
      s.insert({x, y});
    }
    return answer;
  }

 private:
  const int dx[4][3] = {{-1, -1, 0}, {-1, -1, 0}, {0, 1, 1}, {0, 1, 1}};
  const int dy[4][3] = {{0, 1, 1}, {-1, 0, -1}, {-1, -1, 0}, {1, 0, 1}};
};
