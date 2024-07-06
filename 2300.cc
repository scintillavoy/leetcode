#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                              long long success) {
    sort(potions.begin(), potions.end());
    vector<int> result;
    for (const auto spell : spells) {
      long long value = success / spell + (success % spell == 0 ? 0 : 1);
      auto it = lower_bound(potions.begin(), potions.end(), value);
      result.push_back(potions.end() - it);
    }
    return result;
  }
};
