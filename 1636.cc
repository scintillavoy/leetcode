#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    vector<int> counts(201);
    for (const auto num : nums) {
      ++counts[num + 100];
    }
    sort(nums.begin(), nums.end(), [&](const int a, const int b) {
      if (counts[a + 100] != counts[b + 100]) {
        return counts[a + 100] < counts[b + 100];
      }
      return b < a;
    });
    return nums;
  }
};
