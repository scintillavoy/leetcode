#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> combination;
    backtrack(k, n, combination, result);
    return result;
  }

 private:
  void backtrack(int k, int n, vector<int>& combination,
                 vector<vector<int>>& result) {
    if (k == 1) {
      if (n > 9 || (!combination.empty() && n <= combination.back())) {
        return;
      }
      combination.push_back(n);
      result.push_back(combination);
      combination.pop_back();
      return;
    }
    for (int i = combination.empty() ? 1 : combination.back() + 1; i <= 9;
         ++i) {
      combination.push_back(i);
      backtrack(k - 1, n - i, combination, result);
      combination.pop_back();
    }
  }
};
