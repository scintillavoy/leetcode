#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool divideArray(vector<int>& nums) {
    unordered_set<int> s;
    for (const auto num : nums) {
      if (s.contains(num)) {
        s.erase(num);
      } else {
        s.insert(num);
      }
    }
    return s.empty();
  }
};
