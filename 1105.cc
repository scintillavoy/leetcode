#include <algorithm>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    vector<pair<int, int>> dp(shelfWidth + 1, {numeric_limits<int>::max(), 0});
    dp[books[0][0]] = {books[0][1], 0};
    for (int i = 1; i < books.size(); ++i) {
      vector<pair<int, int>> dp_next(shelfWidth + 1,
                                     {numeric_limits<int>::max(), 0});
      for (int j = shelfWidth; j >= 1; --j) {
        if (dp[j].first == numeric_limits<int>::max()) {
          continue;
        }
        if (j + books[i][0] <= shelfWidth) {
          dp_next[j + books[i][0]] = {
              max(dp[j].first, dp[j].second + books[i][1]), dp[j].second};
        }
        if (dp_next[books[i][0]].first > dp[j].first + books[i][1]) {
          dp_next[books[i][0]] = {dp[j].first + books[i][1], dp[j].first};
        }
      }
      dp = dp_next;
    }
    int min_height = numeric_limits<int>::max();
    for (int i = 1; i <= shelfWidth; ++i) {
      min_height = min(min_height, dp[i].first);
    }
    return min_height;
  }
};
