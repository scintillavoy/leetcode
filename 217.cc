#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> exist;
    for (const auto& num : nums) {
      if (exist.count(num) != 0) {
        return true;
      }
      exist.insert(num);
    }
    return false;
  }
};
