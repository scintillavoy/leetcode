#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumBeauty(vector<int>& nums, int k) {
    auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
    int min_val = *min_it - k;
    int max_val = *max_it + k;
    int correction = -min_val;
    min_val += correction;
    max_val += correction;
    vector<int> beauties(max_val + 2);
    for (const auto num : nums) {
      ++beauties[num - k + correction];
      --beauties[num + k + correction + 1];
    }
    int max_beauty = beauties[0];
    for (int i = 1; i < beauties.size() - 1; ++i) {
      beauties[i] += beauties[i - 1];
      max_beauty = max(max_beauty, beauties[i]);
    }
    return max_beauty;
  }
};
