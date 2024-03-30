#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> frequency;
    int answer = 0;
    int left = 0, mid = 0;
    for (int right = 0; right < nums.size(); ++right) {
      ++frequency[nums[right]];
      if (frequency.size() > k) {
        left = mid;
        while (frequency.size() > k) {
          if (frequency[nums[left]] == 1) {
            frequency.erase(nums[left]);
          } else {
            --frequency[nums[left]];
          }
          ++left;
        }
        mid = left;
      }
      if (frequency.size() == k) {
        while (frequency[nums[mid]] > 1) {
          --frequency[nums[mid]];
          ++mid;
        }
        answer += mid - left + 1;
      }
    }
    return answer;
  }
};
