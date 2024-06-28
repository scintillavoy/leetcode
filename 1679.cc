#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxOperations(vector<int>& nums, int k) {
    int result = 0;
    unordered_map<int, int> counts;
    for (const int num : nums) {
      if (counts[k - num] > 0) {
        --counts[k - num];
        ++result;
      } else {
        ++counts[num];
      }
    }
    return result;
  }
};
