#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    int max_value = *max_element(nums.begin(), nums.end());
    long long answer = 0;
    int count = 0;
    int start = 0, end = 0;
    while (end < nums.size()) {
      if (nums[end] == max_value) {
        ++count;
      }
      ++end;
      while (count > k) {
        if (nums[start] == max_value) {
          --count;
        }
        ++start;
      }
      if (count == k) {
        while (nums[start] != max_value) {
          ++start;
        }
        answer += start + 1;
      }
    }
    return answer;
  }
};
