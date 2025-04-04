#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int countPairs(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> num_to_indices;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (const auto j : num_to_indices[nums[i]]) {
        if ((i * j) % k == 0) {
          ++count;
        }
      }
      num_to_indices[nums[i]].push_back(i);
    }
    return count;
  }
};
