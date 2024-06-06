#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    if (nums.size() % k != 0) {
      return false;
    }
    unordered_map<int, int> frequencies;
    for (const auto num : nums) {
      ++frequencies[num];
    }
    for (auto num : nums) {
      while (frequencies[num - 1] > 0) {
        --num;
      }
      while (frequencies[num] > 0) {
        int frequency = frequencies[num];
        for (int i = num; i < num + k; ++i) {
          if (frequencies[i] < frequency) {
            return false;
          }
          frequencies[i] -= frequency;
        }
        ++num;
      }
    }
    return true;
  }
};
