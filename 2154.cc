#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int findFinalValue(vector<int>& nums, int original) {
    unordered_set<int> num_set(nums.begin(), nums.end());
    while (num_set.contains(original)) {
      original <<= 1;
    }
    return original;
  }
};
