#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int waysToPartition(vector<int>& nums, int k) {
    long long left_sum = 0, right_sum = 0;
    unordered_map<long long, int> count_map;
    queue<long long> count_queue;
    for (const auto num : nums) {
      right_sum += num;
    }
    for (int i = 0; i < nums.size() - 1; ++i) {
      left_sum += nums[i];
      right_sum -= nums[i];
      ++count_map[right_sum - left_sum];
      count_queue.push(right_sum - left_sum);
    }
    count_queue.push(0);  // Dummy
    vector<int> results(nums.size() + 1);
    results.back() = count_map[0];
    for (int i = 0; i < nums.size(); ++i) {
      results[i] = count_map[k - nums[i]];
      --count_map[count_queue.front()];
      ++count_map[-count_queue.front()];
      count_queue.pop();
    }
    int max_result = 0;
    for (const auto result : results) {
      max_result = max(max_result, result);
    }
    return max_result;
  }
};
