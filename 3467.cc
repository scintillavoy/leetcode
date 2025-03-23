#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> transformArray(vector<int>& nums) {
    vector<int> result;
    for (const auto num : nums) {
      if (num % 2 == 0) {
        result.push_back(0);
      }
    }
    while (result.size() < nums.size()) {
      result.push_back(1);
    }
    return result;
  }
};
