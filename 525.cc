#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> parity_to_min_index;
    parity_to_min_index[0] = -1;
    int max_length = 0;
    int parity = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        ++parity;
      } else {
        --parity;
      }
      if (parity_to_min_index.contains(parity)) {
        max_length = max(max_length, i - parity_to_min_index[parity]);
      } else {
        parity_to_min_index[parity] = i;
      }
    }
    return max_length;
  }
};
