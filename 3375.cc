#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    unordered_set<int> seen_nums;
    for (const auto num : nums) {
      if (num < k) {
        return -1;
      }
      seen_nums.insert(num);
    }
    seen_nums.erase(k);
    return seen_nums.size();
  }
};
