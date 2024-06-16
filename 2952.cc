#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumAddedCoins(vector<int>& coins, int target) {
    sort(coins.begin(), coins.end());
    long long miss = 1;
    int curr = 0;
    int result = 0;
    while (miss <= target) {
      if (curr < coins.size() && coins[curr] <= miss) {
        miss += coins[curr];
        ++curr;
      } else {
        miss *= 2;
        ++result;
      }
    }
    return result;
  }
};
