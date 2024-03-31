#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long answer = 0;
    int min_index = -1, max_index = -1;
    int start = -1;
    for (int end = 0; end < nums.size(); ++end) {
      if (nums[end] < minK || nums[end] > maxK) {
        start = end;
      }
      if (nums[end] == minK) {
        min_index = end;
      }
      if (nums[end] == maxK) {
        max_index = end;
      }
      answer += max(0, min(min_index, max_index) - start);
    }
    return answer;
  }
};
