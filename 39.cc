#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> combinations;
    vector<int> combination;
    backtrack(candidates, combinations, combination, 0, target);
    return combinations;
  }

 private:
  void backtrack(const vector<int>& candidates,
                 vector<vector<int>>& combinations, vector<int>& combination,
                 int curr_index, int remaining) {
    for (int i = curr_index; i < candidates.size(); ++i) {
      combination.push_back(candidates[i]);
      remaining -= candidates[i];
      if (remaining <= 0) {
        if (remaining == 0) {
          combinations.push_back(combination);
        }
      } else {
        backtrack(candidates, combinations, combination, i, remaining);
      }
      combination.pop_back();
      remaining += candidates[i];
    }
  }
};
