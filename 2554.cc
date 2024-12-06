#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxCount(vector<int>& banned, int n, int maxSum) {
    unordered_set<int> banned_set(banned.begin(), banned.end());
    int sum = 0;
    int count = 0;
    for (int num = 1; num <= n; ++num) {
      if (banned_set.contains(num)) {
        continue;
      }
      if (sum + num > maxSum) {
        break;
      }
      sum += num;
      ++count;
    }
    return count;
  }
};
