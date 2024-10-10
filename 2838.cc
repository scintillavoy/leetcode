#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters,
                                 vector<int>& coins) {
    vector<pair<int, long long>> monster_coin_pairs(monsters.size());
    for (int i = 0; i < monsters.size(); ++i) {
      monster_coin_pairs[i] = {monsters[i], coins[i]};
    }
    sort(monster_coin_pairs.begin(), monster_coin_pairs.end());
    for (int i = 1; i < monster_coin_pairs.size(); ++i) {
      monster_coin_pairs[i].second += monster_coin_pairs[i - 1].second;
    }
    vector<long long> max_coins(heroes.size());
    for (int i = 0; i < heroes.size(); ++i) {
      int low = 0, high = monster_coin_pairs.size() - 1;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (heroes[i] < monster_coin_pairs[mid].first) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      if (low > 0) {
        max_coins[i] = monster_coin_pairs[low - 1].second;
      }
    }
    return max_coins;
  }
};
