#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    unordered_set<int> candidates;
    for (int i = 0; i < nums.size(); ++i) {
      candidates.insert(i + 1);
    }
    int duplicated = 0;
    for (const auto num : nums) {
      if (candidates.contains(num)) {
        candidates.erase(num);
      } else {
        duplicated = num;
      }
    }
    int missing = *candidates.begin();
    return {duplicated, missing};
  }
};
