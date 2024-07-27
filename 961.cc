#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int repeatedNTimes(vector<int>& nums) {
    unordered_set<int> s;
    for (const auto num : nums) {
      if (s.count(num) != 0) {
        return num;
      }
      s.insert(num);
    }
    return -1;
  }
};
