#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    unordered_set<int> seen_nums;
    for (const auto num : nums) {
      if (num > 0) {
        seen_nums.insert(num);
      }
    }
    return seen_nums.size();
  }
};
