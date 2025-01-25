#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<pair<int, int>> num_index_pairs(n);
    for (int i = 0; i < n; ++i) {
      num_index_pairs[i] = {nums[i], i};
    }
    sort(num_index_pairs.begin(), num_index_pairs.end());
    vector<int> result(n);
    int left = 0;
    while (left < n) {
      vector<int> indexes;
      indexes.push_back(num_index_pairs[left].second);
      int right = left + 1;
      while (right < n &&
             num_index_pairs[right].first - num_index_pairs[right - 1].first <=
                 limit) {
        indexes.push_back(num_index_pairs[right].second);
        ++right;
      }
      sort(indexes.begin(), indexes.end());
      for (int i = left; i < right; ++i) {
        result[indexes[i - left]] = num_index_pairs[i].first;
      }
      left = right;
    }
    return result;
  }
};
