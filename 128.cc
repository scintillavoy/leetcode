#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s;
    for (const auto num : nums) {
      s.insert(num);
    }
    int result = 0;
    while (!s.empty()) {
      int curr = *s.cbegin();
      s.erase(curr);
      int start = curr, end = curr;
      while (s.count(start - 1) > 0) {
        --start;
        s.erase(start);
      }
      while (s.count(end + 1) > 0) {
        ++end;
        s.erase(end);
      }
      result = max(result, end - start + 1);
    }
    return result;
  }
};
