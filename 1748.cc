#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> counts;
    for (const auto num : nums) {
      ++counts[num];
    }
    int sum = 0;
    for (const auto [num, count] : counts) {
      if (count == 1) {
        sum += num;
      }
    }
    return sum;
  }
};
