#include <vector>
using namespace std;

class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    int result = 0;
    for (const auto num : nums) {
      if (num % 3 != 0) {
        ++result;
      }
    }
    return result;
  }
};
