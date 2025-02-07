#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    vector<int> results;
    unordered_map<int, int> ball_to_color;
    unordered_map<int, int> color_to_count;
    for (const auto& query : queries) {
      int ball = query[0];
      int color = query[1];
      if (ball_to_color.contains(ball)) {
        int old_color = ball_to_color[ball];
        --color_to_count[old_color];
        if (color_to_count[old_color] == 0) {
          color_to_count.erase(old_color);
        }
      }
      ball_to_color[ball] = color;
      ++color_to_count[color];
      results.push_back(color_to_count.size());
    }
    return results;
  }
};
