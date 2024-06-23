#include <algorithm>
#include <deque>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    deque<pair<int, int>> inc, dec;
    int result = 0;
    int start = 0;
    for (int end = 0; end < nums.size(); ++end) {
      while (!inc.empty() && inc.back().first > nums[end]) {
        inc.pop_back();
      }
      while (!dec.empty() && dec.back().first < nums[end]) {
        dec.pop_back();
      }
      inc.push_back({nums[end], end});
      dec.push_back({nums[end], end});
      while (dec.front().first - inc.front().first > limit) {
        ++start;
        while (!inc.empty() && inc.front().second < start) {
          inc.pop_front();
        }
        while (!dec.empty() && dec.front().second < start) {
          dec.pop_front();
        }
      }
      result = max(result, end - start + 1);
    }
    return result;
  }
};
