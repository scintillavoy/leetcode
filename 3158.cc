#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int duplicateNumbersXOR(vector<int>& nums) {
    int result = 0;
    unordered_set<int> seen_nums;
    for (const auto num : nums) {
      if (seen_nums.contains(num)) {
        result ^= num;
      } else {
        seen_nums.insert(num);
      }
    }
    return result;
  }
};
