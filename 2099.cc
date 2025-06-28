#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<pair<int, int>> num_index_pairs(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      num_index_pairs[i] = {nums[i], i};
    }
    sort(num_index_pairs.begin(), num_index_pairs.end());
    vector<int> subsequence(k);
    for (int i = 0; i < k; ++i) {
      subsequence[i] = num_index_pairs[num_index_pairs.size() - 1 - i].second;
    }
    sort(subsequence.begin(), subsequence.end());
    for (int i = 0; i < subsequence.size(); ++i) {
      subsequence[i] = nums[subsequence[i]];
    }
    return subsequence;
  }
};
