#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    unordered_map<int, int> frequency;
    int answer = 0;
    int left = 0, right = 0;
    while (right < nums.size()) {
      ++frequency[nums[right]];
      while (frequency[nums[right]] > k) {
        --frequency[nums[left]];
        ++left;
      }
      ++right;
      answer = max(answer, right - left);
    }
    return answer;
  }
};
