#include <algorithm>
#include <limits>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minAreaRect(vector<vector<int>>& points) {
    auto hash = [](const pair<int, int>& x) { return x.first ^ x.second; };
    unordered_set<pair<int, int>, decltype(hash)> s;
    for (const auto& point : points) {
      s.insert({point[0], point[1]});
    }
    sort(points.begin(), points.end());
    int answer = numeric_limits<int>::max();
    for (int i = 0; i < points.size(); ++i) {
      int x = points[i][0];
      int y = points[i][1];
      for (int j = i + 1; j < points.size(); ++j) {
        int x2 = points[j][0];
        int y2 = points[j][1];
        if (x < x2 && y < y2 && s.count({x, y2}) == 1 &&
            s.count({x2, y}) == 1) {
          answer = min(answer, (x2 - x) * (y2 - y));
        }
      }
    }
    if (answer == numeric_limits<int>::max()) {
      answer = 0;
    }
    return answer;
  }
};
