#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  Solution(vector<int>& nums) {
    random_device rd;
    random_engine.seed(rd());
    for (int i = 0; i < nums.size(); ++i) {
      indices[nums[i]].push_back(i);
    }
  }

  int pick(int target) {
    return indices[target][random_engine() % indices[target].size()];
  }

 private:
  default_random_engine random_engine;
  unordered_map<int, vector<int>> indices;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
