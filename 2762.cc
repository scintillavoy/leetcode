#include <deque>
#include <vector>
using namespace std;

class Solution {
 public:
  long long continuousSubarrays(vector<int>& nums) {
    long long num_of_continuous_subarrays = 0;
    deque<int> max_dq, min_dq;
    int left = 0;
    for (int right = 0; right < nums.size(); ++right) {
      while (!max_dq.empty() && nums[max_dq.back()] < nums[right]) {
        max_dq.pop_back();
      }
      max_dq.push_back(right);
      while (!min_dq.empty() && nums[min_dq.back()] > nums[right]) {
        min_dq.pop_back();
      }
      min_dq.push_back(right);
      while (nums[max_dq.front()] - nums[min_dq.front()] > 2) {
        if (max_dq.front() < min_dq.front()) {
          left = max_dq.front() + 1;
          max_dq.pop_front();
        } else {
          left = min_dq.front() + 1;
          min_dq.pop_front();
        }
      }
      num_of_continuous_subarrays += right - left + 1;
    }
    return num_of_continuous_subarrays;
  }
};
