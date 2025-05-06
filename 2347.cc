#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string bestHand(vector<int>& ranks, vector<char>& suits) {
    for (int i = 1; i < suits.size(); ++i) {
      if (suits[i - 1] != suits[i]) {
        break;
      }
      if (i + 1 == suits.size()) {
        return "Flush";
      }
    }
    vector<int> rank_counts(14);
    int max_rank_count = 0;
    for (const auto rank : ranks) {
      ++rank_counts[rank];
      max_rank_count = max(max_rank_count, rank_counts[rank]);
    }
    if (max_rank_count >= 3) {
      return "Three of a Kind";
    }
    if (max_rank_count >= 2) {
      return "Pair";
    }
    return "High Card";
  }
};
