#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    vector<int> max_sizes(n, 1);
    int max_size = 1;
    vector<int> previous_indices(n);
    for (int i = 0; i < n; ++i) {
      previous_indices[i] = i;
    }
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0 && max_sizes[i] < max_sizes[j] + 1) {
          max_sizes[i] = max_sizes[j] + 1;
          max_size = max(max_size, max_sizes[i]);
          previous_indices[i] = j;
        }
      }
    }
    vector<int> result;
    for (int i = 0; i < n; ++i) {
      if (max_sizes[i] == max_size) {
        int index = i;
        while (previous_indices[index] != index) {
          result.push_back(nums[index]);
          index = previous_indices[index];
        }
        result.push_back(nums[index]);
        break;
      }
    }
    return result;
  }
};
