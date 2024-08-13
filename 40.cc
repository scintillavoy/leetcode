#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> combination;
    backtrack(0, -1, target, candidates, result, combination);
    return result;
  }

 private:
  void backtrack(int index, int previous_value, int target,
                 const vector<int> &candidates, vector<vector<int>> &result,
                 vector<int> &combination) {
    if (target == 0) {
      result.push_back(combination);
    }
    if (target <= 0 || index >= candidates.size()) {
      return;
    }
    if (candidates[index] != previous_value) {
      combination.push_back(candidates[index]);
      backtrack(index + 1, previous_value, target - candidates[index],
                candidates, result, combination);
      combination.pop_back();
    }
    backtrack(index + 1, candidates[index], target, candidates, result,
              combination);
  }
};
